# Makefile

CC = gcc -pedantic -Wall -O3
TEX = pdflatex

all: build doc

build: C/simple C/reboot
		
C/reboot: C/reboot.c
	$(CC) $< -o $@

C/simple: C/simple.c
	$(CC) $< -o $@

doc: doc/doc.pdf

doc/doc.pdf: doc/doc.tex doc/prelude.tex
	$(MAKE) -C doc -f ../Makefile doc.pdf

doc.pdf: doc.tex prelude.tex
	$(TEX) $<
	$(TEX) $<

clean:
	$(RM) C/simple
	$(RM) doc/*.out doc/*.log doc/.*aux

fullclean: clean
	$(RM) doc/*.pdf

.PHONY: all build doc tests clean fullclean
