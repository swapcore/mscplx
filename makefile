compile:
	gcc -o mscplx \
		main.c \
		format/id3v230/id3v230.c \
		tools/name.c \
		tools/queue.c\
		tools/title.c \
		tools/track.c \
		mscplx.c