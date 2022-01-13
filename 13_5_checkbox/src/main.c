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

void on_chkbtn_1_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	//g_print("%s\n", gtk_widget_get_name(GTK_WIDGET(togglebutton)));
	
	if (gtk_toggle_button_get_active(togglebutton)) {
		g_print("Option 1 is Checked\n");
	}
	else {
		g_print("Option 1 is Unchecked\n");
	}
}

void on_chkbtn_2_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
		g_print("Option 2 is Checked\n");
	}
	else {
		g_print("Option 2 is Unchecked\n");
	}
}

void on_chkbtn_3_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
		g_print("Option 3 is Checked\n");
	}
	else {
		g_print("Option 3 is Unchecked\n");
	}
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
