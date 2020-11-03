CC = g++
LIBS = -std=c++17

lazymake: src/main.cpp src/lazycompile.cpp src/filemachine.cpp
	$(CC) $(LIBS) -o lazymake src/main.cpp src/lazycompile.cpp src/filemachine.cpp

install: SHELL:=/bin/bash
install:
	@a=$$(pwd);\
	b=/lazymake;\
	p='/usr/local/bin';\
	cp $$a$$b $$p;\
	if [ "$$(uname)" == "Darwin" ];\
	then chmod 755 $$p$$b;\
	else chmod +x $$p$$b;\
	fi

clean:
	rm -f lazymake
	rm -f /usr/local/bin/lazymake