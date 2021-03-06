/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_DISPLAY_SETTINGS_H
#define GUI_DISPLAY_SETTINGS_H


#include "gui_frame.h"
#include "components/gui_divider.h"
#include "components/gui_label.h"
#include "components/gui_button.h"
#include "components/gui_numberinput.h"

#define COLORS_MAX_BUTTONS (28)
#define BUF_MAXLEN_MS_FORMAT (16)


/**
 * Display settings dialog
 * @author Hj. Malthaner
 */
class color_gui_t : public gui_frame_t, private action_listener_t
{
private:

	button_t buttons[COLORS_MAX_BUTTONS];

	gui_numberinput_t
		brightness,
		scrollspeed,
		traffic_density,
		inp_underground_level,
		cursor_hide_range;

	gui_label_t
		brightness_label,
		scrollspeed_label,
		hide_buildings_label,
		traffic_density_label,
		convoy_tooltip_label,
		frame_time_label,
		frame_time_value_label,
		idle_time_label,
		idle_time_value_label,
		fps_label,
		fps_value_label,
		simloops_label,
		simloops_value_label;

	gui_divider_t
		divider1,
		divider2,
		divider3,
		divider4;

	gui_container_t
		label_container,
		value_container;

public:
	color_gui_t();

	/**
	 * Some windows have associated help text.
	 * @return The help file name or NULL
	 * @author Hj. Malthaner
	 */
	const char * get_help_filename() const OVERRIDE { return "display.txt"; }

	void draw(scr_coord pos, scr_size size) OVERRIDE;

	bool action_triggered(gui_action_creator_t*, value_t) OVERRIDE;

	virtual void set_windowsize(scr_size size) OVERRIDE;
};

#endif
