#include "gui.h"
#include "loop.h"

void init_window(int argc, char **argv) {
	
	GtkWidget *window;
	GtkWidget *hbox;
	GtkWidget *start;
	GtkWidget *stop;
	gtk_init (&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	
	hbox = gtk_hbox_new (FALSE, 2);
	start = gtk_button_new_with_label ("Start loop");
	stop = gtk_button_new_with_label ("Break loop");
	
	gtk_container_add (GTK_CONTAINER (window), hbox);
	
	gtk_signal_connect (GTK_OBJECT (start), "clicked",
                        GTK_SIGNAL_FUNC (start_loop), NULL);
	gtk_signal_connect (GTK_OBJECT (stop), "clicked",
                        GTK_SIGNAL_FUNC (exit_check), NULL);

	gtk_box_pack_start(GTK_BOX(hbox), start, FALSE, FALSE, 2);
	gtk_box_pack_start(GTK_BOX(hbox), stop, FALSE, FALSE, 2);
	
	gtk_widget_show(hbox);
	gtk_widget_show(start);
	gtk_widget_show(stop);
	gtk_widget_show(window);
	
	
	gtk_main();


}




