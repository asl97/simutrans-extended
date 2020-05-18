/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef BODEN_BRUECKENBODEN_H
#define BODEN_BRUECKENBODEN_H


#include "grund.h"

class brueckenboden_t : public grund_t
{
private:
	uint8 weg_hang;

protected:
	void calc_image_internal(const bool calc_only_snowline_change);

public:
	brueckenboden_t(loadsave_t *file, koord pos ) : grund_t(koord3d(pos,0) ) { rdwr(file); }
	brueckenboden_t(koord3d pos, int grund_hang, int weg_hang);

	virtual void rdwr(loadsave_t *file);

	// map rotation
	virtual void rotate90();

	virtual sint8 get_weg_yoff() const;

	slope_t::type get_weg_hang() const { return weg_hang; }

	const char *get_name() const {return "Brueckenboden";}
	typ get_typ() const { return brueckenboden; }

	void info(cbuffer_t & buf) const OVERRIDE;
};

#endif
