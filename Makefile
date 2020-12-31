PYTHON ?= python3
REQ_MINOR_VERSION = 6

all : | env build
	@echo "Build complete! You can run dupeGuru with 'make run'"

# If you're installing into a path that is not going to be the final path prefix (such as a
# sandbox), set DESTDIR to that path.

# Our build scripts are not very "make like" yet and perform their task in a bundle. For now, we
# use one of each file to act as a representative, a target, of these groups.
submodules_target = hscommon/__init__.py

reqs :
	@ret=`${PYTHON} -c "import sys; print(int(sys.version_info[:2] >= (3, ${REQ_MINOR_VERSION})))"`; \
		if [ $${ret} -ne 1 ]; then \
			echo "Python 3.${REQ_MINOR_VERSION}+ required. Aborting."; \
			exit 1; \
		fi
	@${PYTHON} -m venv -h > /dev/null || \
		echo "Creation of our virtualenv failed. Something's wrong with your python install."

# Ensure that submodules are initialized
$(submodules_target) :
	git submodule init
	git submodule update

env : | $(submodules_target) reqs
	@echo "Creating our virtualenv"
	${PYTHON} -m venv env
	./env/bin/python -m pip install -r requirements.txt

build:
	./env/bin/python build.py

run:
	./env/bin/python run.py

.PHONY : reqs build run all