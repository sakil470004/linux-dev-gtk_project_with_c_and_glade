#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

typedef struct {
    GtkWidget *w_webkit_webview;
} app_widgets;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    app_widgets     *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);
    
    // Workaround from: https://bugs.webkit.org/show_bug.cgi?id=175937
    //g_object_unref (g_object_ref_sink (webkit_web_view_new ()));
    webkit_web_view_get_type();
    webkit_settings_get_type();

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    widgets->w_webkit_webview  = GTK_WIDGET(gtk_builder_get_object(builder, "webkit_webview"));
    
    gtk_builder_connect_signals(builder, widgets);
    
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(widgets->w_webkit_webview), "http://prognotes.net");

    g_object_unref(builder);

    gtk_widget_show_all(window);
    gtk_main();
    g_slice_free(app_widgets, widgets);

    return 0;
}

// User presses Enter in the URL bar
void on_entry_url_activate(GtkEntry *entry, app_widgets *app_wdgts)
{
    const gchar *the_url;
    
    the_url = gtk_entry_get_text(entry);
    
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(app_wdgts->w_webkit_webview), the_url);
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
