
#include <stdio.h>
#include <stdlib.h>

#include "rc.h"
#include "wmprefs.h"

/* Set the default values */
void wmprefs_load_defaults(struct wmprefs_t *p)
{
    printf("Loading defaults\n");
    p->focus_border_col[0] = 0;
    p->focus_border_col[1] = 180;
    p->focus_border_col[2] = 0;

    p->unfocus_border_col[0] = 0;
    p->unfocus_border_col[1] = 0;
    p->unfocus_border_col[2] = 0;

    p->fg_col[0] = 0;
    p->fg_col[1] = 0;
    p->fg_col[2] = 0;

    p->bg_col[0] = 215;
    p->bg_col[1] = 215;
    p->bg_col[2] = 215;

    p->launcher_font = "*-courier*standard*-14-*";

    p->alttab_font = "*-courier*standard*-14-*";
    p->alttab_char_width = 50;

    p->bw = 1;
    p->snap_width = 15;
}

void wmprefs_read_config_files(struct wmprefs_t *p)
{
    struct rc_t R;

    rc_add_int_option(&R, "alttab_char_width", &(p->alttab_char_width));
    rc_add_int_option(&R, "border_width", &(p->bw));
    rc_add_int_option(&R, "snap_width", &(p->snap_width));

    rc_add_colour_option(&R, "focus_border_col", p->focus_border_col);
    rc_add_colour_option(&R, "unfocus_border_col", p->unfocus_border_col);
    rc_add_colour_option(&R, "fg_col", p->fg_col);
    rc_add_colour_option(&R, "bg_col", p->bg_col);

    rc_add_string_option(&R, "launcher_font", &(p->launcher_font));
    rc_add_string_option(&R, "alttab_font", &(p->switcher_font));
}
