.SILENT:

.PHONY: run
run: 
	gcc back/main.c -o .temp/webproc 
	sudo ./.temp/webproc

