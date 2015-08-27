# Library Overlay

This minimal working example serves the purpose of showing how to
write a simple overlay library for any shared object library in a
Linux system.


## What it does

When applications launch, many of them make use of shared object
libraryes (`lib*.so`). Using the `LD_PRELOAD` environmental variable,
these libraries can be overridden to replace their functionality in
part, or completely. This example shows how replacement libraries are
written and compiled for this purpose.


## "But ..."

... you may say, when the original library is not being loaded, you
need to re-implement all of its functionality to actually work.

Not so.

Using the `dlsym` functionality for loading shared objects, you can

 * Load all missing symbols into memory, letting the guest application
   access all functions that you didn't bother to re-implement from
   the original library, and

 * Forward calls to the original library after you "cleaned" its
   input, afterwards "cleaning" its output.

Accompanied to this example is a replacement `libX11.so`
implementation that replaces the functions `XCreateWindow` and
`XCreateSimpleWindow`. Both calls are forwarded to the original
`libX11.so` library, but ther invocation (and part of their
parameters) are printed to `std::cout`.


## Trying it

Clone the repository, go into its directory, and call

```bash
$ ./run.sh gedit
```

Or replace `gedit` with any application you'd like to see interacting
with X11.


## Disclaimer

This example is solely meant for educational purposes and was derived
from trying to smartly position X11 windows directly after their
creation.

Don't do things with it that are not allowed in your country.

The whole code and this "documentation" is licensed under BSD. If you
use it in part or completely, obey the BSD rules.
