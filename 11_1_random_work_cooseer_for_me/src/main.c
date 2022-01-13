#include <gtk/gtk.h>

typedef struct
{
    // Radio Buttons
    GtkWidget *w_rb_none;
    //my rb
    GtkWidget *w_rb_absolute_order;
    GtkWidget *w_rb_code_see;
    GtkWidget *w_rb_code_learn;
    GtkWidget *w_rb_codeforce;
    GtkWidget *w_rb_github;
    GtkWidget *w_rb_cs50;
    GtkWidget *w_rb_learn_japanese;
    GtkWidget *w_rb_gtk_project;
    // Labels
    GtkWidget *w_lbl_result;
    GtkWidget *w_lbl_win_lose;
    GtkWidget *w_lbl_your_bet;
    // Buttons
    GtkWidget *w_btn_toss;
    GtkWidget *w_btn_play_again;
} app_widgets;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;
    app_widgets *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    // Get pointer to main window
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    // Get pointers to widgets//for connect pointer need id
    //radio
    widgets->w_rb_none = GTK_WIDGET(gtk_builder_get_object(builder, "rb_none"));

    widgets->w_rb_absolute_order = GTK_WIDGET(gtk_builder_get_object(builder, "rb_absolute_order"));
    widgets->w_rb_code_see = GTK_WIDGET(gtk_builder_get_object(builder, "rb_code_see"));
    widgets->w_rb_code_learn = GTK_WIDGET(gtk_builder_get_object(builder, "rb_code_learn"));
    widgets->w_rb_codeforce = GTK_WIDGET(gtk_builder_get_object(builder, "rb_codeforce"));
    widgets->w_rb_github = GTK_WIDGET(gtk_builder_get_object(builder, "rb_github"));
    widgets->w_rb_cs50 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_cs50"));
    widgets->w_rb_learn_japanese = GTK_WIDGET(gtk_builder_get_object(builder, "rb_learn_japanese"));
    widgets->w_rb_gtk_project = GTK_WIDGET(gtk_builder_get_object(builder, "rb_gtk_project"));

    //lebel
    widgets->w_lbl_result = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_result"));
    widgets->w_lbl_win_lose = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_win_lose"));
    widgets->w_lbl_your_bet = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_your_bet"));
    //button
    widgets->w_btn_toss = GTK_WIDGET(gtk_builder_get_object(builder, "btn_toss"));
    widgets->w_btn_play_again = GTK_WIDGET(gtk_builder_get_object(builder, "btn_play_again"));

    gtk_builder_connect_signals(builder, widgets);
    g_object_unref(builder);
    gtk_widget_show(window);

    gtk_main();
    g_slice_free(app_widgets, widgets);

    return 0;
}

// Either "Heads" or "Tails" radio button clicked
void on_rb_toggled(GtkToggleButton *togglebutton, app_widgets *wdgts)
{
    // A radio button was selected, so enable the "Toss Coin" button
    gtk_widget_set_sensitive(wdgts->w_btn_toss, TRUE);

    // Find the selected radio button and update the selection in the text under "Your Bet:"
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_absolute_order)))
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "Absolute Order");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_code_see)))
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "Code See");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_code_learn)))
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "Code Learn");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_codeforce)))
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "Codeforce");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_github)))
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "Github or Source");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_cs50)))
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "CS_50");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_learn_japanese)))
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "Learn Japanese");
    }
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_gtk_project)))
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "GTK Project");
    }
}

// "Toss Coin" button clicked
void on_btn_toss_clicked(GtkButton *button, app_widgets *wdgts)
{
    int result; // Result of coin toss
    // Win and Lose text strings and settings
    // Win and Lose text strings and settings, change label color in GTK here
    gchar str_win[] = "<span foreground='green' weight='bold' font='14'>You Win!</span>";
    gchar str_lose[] = "<span foreground='red' weight='bold' font='14'>You Lose!</span>";

    // Toss the coin
    result = g_random_int() % 8;
    // result = g_random_boolean();
    // Set the text to either "Heads" or "Tails" under the "Coin Toss Result:" heading
    if (result == 0)
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "Absolute Order");
    }
    else if (result == 1)
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "Code See");
    }
    else if (result == 2)
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "Code Learn");
    }
    else if (result == 3)
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "Codeforce");
    }
    else if (result == 4)
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "Github or Source");
    }
    else if (result == 5)
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "CS_50");
    }
    else if (result == 6)
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "Learn Japanese");
    }
    else if (result == 7)
    {
        gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "GTK Project");
    }

    // Determine if player won or lost the game, depending on bet placed
    if ((result == 0) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_absolute_order)))
    {
        // Player bet on heads and coin toss resulted in heads
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_win);
    }
    else if ((result == 1) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_code_see)))
    {
        //
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_win);
    }
    else if ((result == 2) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_code_learn)))
    {
        //
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_win);
    }
    else if ((result == 3) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_codeforce)))
    {
        //
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_win);
    }
    else if ((result == 4) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_github)))
    {
        //
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_win);
    }
    else if ((result == 5) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_cs50)))
    {
        //
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_win);
    }
    else if ((result == 6) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_learn_japanese)))
    {
        //
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_win);
    }
    else if ((result == 7) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_gtk_project)))
    {
        //
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_win);
    }

    else
    {
        // Player lost the game
        gtk_label_set_markup(GTK_LABEL(wdgts->w_lbl_win_lose), str_lose);
    }

    // Show "Play Again" button
    gtk_widget_set_visible(wdgts->w_btn_play_again, TRUE);
    // Hide "Toss Coin" button
    gtk_widget_set_visible(wdgts->w_btn_toss, FALSE);
    // Disable "Toss Coin" buttons and radio buttons
    gtk_widget_set_sensitive(wdgts->w_btn_toss, FALSE);

    gtk_widget_set_sensitive(wdgts->w_rb_absolute_order, FALSE);
    gtk_widget_set_sensitive(wdgts->w_rb_code_see, FALSE);
    gtk_widget_set_sensitive(wdgts->w_rb_code_learn, FALSE);
    gtk_widget_set_sensitive(wdgts->w_rb_codeforce, FALSE);
    gtk_widget_set_sensitive(wdgts->w_rb_github, FALSE);
    gtk_widget_set_sensitive(wdgts->w_rb_cs50, FALSE);
    gtk_widget_set_sensitive(wdgts->w_rb_learn_japanese, FALSE);
    gtk_widget_set_sensitive(wdgts->w_rb_gtk_project, FALSE);
}

// "Play Again" button clicked, so reset the game
void on_btn_play_again_clicked(GtkButton *button, app_widgets *wdgts)
{
    // Enable radio buttons
    gtk_widget_set_sensitive(wdgts->w_rb_absolute_order, TRUE);
    gtk_widget_set_sensitive(wdgts->w_rb_code_see, TRUE);
    gtk_widget_set_sensitive(wdgts->w_rb_code_learn, TRUE);
    gtk_widget_set_sensitive(wdgts->w_rb_codeforce, TRUE);
    gtk_widget_set_sensitive(wdgts->w_rb_github, TRUE);
    gtk_widget_set_sensitive(wdgts->w_rb_cs50, TRUE);
    gtk_widget_set_sensitive(wdgts->w_rb_learn_japanese, TRUE);
    gtk_widget_set_sensitive(wdgts->w_rb_gtk_project, TRUE);

    // Select "none" radio button
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(wdgts->w_rb_none), TRUE);
    // Hide "Play Again" button
    gtk_widget_set_visible(wdgts->w_btn_play_again, FALSE);
    // Reset labels
    gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_your_bet), "Select?");
    gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_result), "Decied?");
    gtk_label_set_text(GTK_LABEL(wdgts->w_lbl_win_lose), "Will You Win or Lose?");
    // Show "Toss Coin" button
    gtk_widget_set_visible(wdgts->w_btn_toss, TRUE);
    // Disable "Toss Coin" buton
    gtk_widget_set_sensitive(wdgts->w_btn_toss, FALSE);
}

// Called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}