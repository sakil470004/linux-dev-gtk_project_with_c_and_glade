#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_chkbtn_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	// Print the check button name
	//g_print("%s\n", gtk_widget_get_name(GTK_WIDGET(togglebutton)));
	
	// Find out which check button was clicked
	if (g_strcmp0(gtk_widget_get_name(GTK_WIDGET(togglebutton)), "option_1") == 0) {
		g_print("Option 1 ");
	}
	else if (g_strcmp0(gtk_widget_get_name(GTK_WIDGET(togglebutton)), "option_2") == 0) {
		g_print("Option 2 ");
	}
	else if (g_strcmp0(gtk_widget_get_name(GTK_WIDGET(togglebutton)), "option_3") == 0) {
		g_print("Option 3 ");
	}
	else {
		g_print("Something went wrong!\n");
	}
	
	// Check whether check button was checked or unchecked
	if (gtk_toggle_button_get_active(togglebutton)) {
		g_print("is Checked\n");
	}
	else {
		g_print("is Unchecked\n");
	}
}


// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
