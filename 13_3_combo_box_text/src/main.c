#include <gtk/gtk.h>

typedef struct
{
    GtkWidget *w_comboboxtext_options;
    GtkWidget *w_lbl_sel_num;
    GtkWidget *w_lbl_sel_text;
} app_widgets;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;

    app_widgets *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);

    // builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    // Update October 2019: The line below replaces the 2 lines above
    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    // get pointers to widgets
    widgets->w_comboboxtext_options = GTK_WIDGET(gtk_builder_get_object(builder, "comboboxtext_options"));
    widgets->w_lbl_sel_num = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_sel_num"));
    widgets->w_lbl_sel_text = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_sel_text"));

    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    g_slice_free(app_widgets, widgets);

    return 0;
}


// Show Option button clicked by user
void on_btn_show_option_clicked(GtkButton *button, app_widgets *app_wdgts)
{
	gint  item_num = 0;		// selected item number from text combo box
	gchar *item_text = 0;	// selected item text from text combo box
	GString *gstr_sel_text;	// dynamic string for converting number to string
	// create a new empty string
	gstr_sel_text = g_string_new("");
	
	// ---- Item Number ----
	// get selected item number from GtkComboBoxText object
	item_num = gtk_combo_box_get_active(GTK_COMBO_BOX(app_wdgts->w_comboboxtext_options));
	// print the selected number to the dynamic string
	g_string_printf(gstr_sel_text, "Item: %d", item_num);
	// display selected item number in text label
	gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_sel_num), gstr_sel_text->str);
	// free up memory from dynamically allocated string
	g_string_free(gstr_sel_text, TRUE);
	
	// ---- Item Text ----
	// get selected item text from GtkComboBoxText object
	item_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(app_wdgts->w_comboboxtext_options));
	if (item_text == NULL) {
		// return if no text found in combo box
		return;
	}
	gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_sel_text), item_text);
	// free up dynamically allocated memory
	g_free(item_text);
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}