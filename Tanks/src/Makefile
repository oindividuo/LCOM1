COMPILER_TYPE= gnu

CC=gcc

PROG=	Tanks
SRCS=   main.c vbe.c video_gr.c timer.c kbd.c bitmap.c tank.c mouse.c

CCFLAGS= -Wall

DPADD+=	${LIBDRIVER} ${LIBSYS}
LDADD+=	-llm -ldriver -lsys

LDFLAGS+= -L .

MAN=

.include <bsd.prog.mk>
.include <bsd.gcc.mk>