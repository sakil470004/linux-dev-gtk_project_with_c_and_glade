#include <gtk/gtk.h>

GtkWidget *g_lbl_coin;
int count = 0;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;

    gtk_init(&argc, &argv);

    // builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    // Update October 2019: The line below replaces the 2 lines above
    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_lbl_coin = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_coin"));//builder,id;

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}
void on_lbl_toss_clicked()
{
    if (count % 2 == 0)
    {
        gboolean result;

        result = g_random_boolean();
        if (result == TRUE)
        {
            gtk_label_set_text(GTK_LABEL(g_lbl_coin), "HEAD");
            g_print("Heads\n");
        }
        else
        {
            g_print("Tails\n");
            gtk_label_set_text(GTK_LABEL(g_lbl_coin), "Tails");//reference //text;
        }
    }else{
         gtk_label_set_text(GTK_LABEL(g_lbl_coin), "Next toss");
    }
    count++;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}