# dupeguru-cocoa

This is the Cocoa UI for [dupeGuru][dupeguru]. This code was previously directly in the main repo,
but since I'm not planning on supporting MacOS myself any longer, I'm splitting it out.

Also, to make the job easier on a would-be maintainer for the Cocoa UI of dupeGuru, I'm planning
on restoring the XCode/XIB version of the UI from the grave.

### OS X maintainer wanted

My Mac Mini is already a couple of years old and is likely to be my last Apple purchase. When it
dies, I will be unable maintain the OS X version of moneyGuru. I've already stopped paying for the
Mac Developer membership so I can't sign the apps anymore (in the "official way" I mean. The
download is still PGP signed) If you're a Mac developer and are interested in taking this task,
[don't hesitate to let me know][contrib-issue].

## How to build dupeGuru from source

### Prerequisites

* Python 3.6+ compiled in "framework mode".
* MacOS 10.12+ with XCode command line tools.

### make

You can build the app with `make`:

    $ make
    $ make run

### pyenv

[pyenv][pyenv] is a popular way to manage multiple python versions. However, be aware that dupeGuru
will not compile with a pyenv's python unless it's been built with `--enable-framework`. You can do
this with:

    $ env PYTHON_CONFIGURE_OPTS="--enable-framework" pyenv install 3.4.3


[dupeguru]: https://github.com/hsoft/dupeguru
[contrib-issue]: https://github.com/hsoft/dupeguru/issues/300
[pyenv]: https://github.com/yyuu/pyenv