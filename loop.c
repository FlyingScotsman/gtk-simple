#include <windows.h>
#include "loop.h"

int exit_loop = 0;

static gpointer loop(gpointer data) {
	// Loop forever
	while (exit_loop != 1) {
		printf("Looping \n");
		Sleep(10);
	}
	printf("Terminating the program...\n");
	Sleep(1000);
	gtk_main_quit();
}

void exit_check() {
	exit_loop = 1;
}

void start_loop() {
	GError    *error = NULL;
	GThread *loop_thread;
	
	loop_thread = g_thread_create( loop, NULL, TRUE, &error );
	
}

