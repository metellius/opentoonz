

#ifndef NOT_SIMMETRIC_BEZIER_POTENTIAL_H
#define NOT_SIMMETRIC_BEZIER_POTENTIAL_H

/**
 * @author  Fabrizio Morciano <fabrizio.morciano@gmail.com>
 */

//#include "tcommon.h"
//#include "tstroke.h"

#include "ext/Potential.h"

#undef DVAPI
#undef DVVAR
#ifdef TNZEXT_EXPORTS
#define DVAPI DV_EXPORT_API
#define DVVAR DV_EXPORT_VAR
#else
#define DVAPI DV_IMPORT_API
#define DVVAR DV_IMPORT_VAR
#endif

namespace ToonzExt
{
class DVAPI
	NotSimmetricBezierPotential
	: public Potential
{
public:
	virtual ~NotSimmetricBezierPotential();

	// chiama compute_value ma effettua un controllo del parametro
	virtual double
	value_(double radiusToTest) const;

	virtual void
	setParameters_(const TStroke *ref,
				   double w,
				   double actionLength);

	Potential *
	clone();

private:
	double compute_shape(double) const; // funzione ausiliaria per
	// il calcolo del parametro
	// da usare

	double compute_value(double) const; // funzione ausiliaria per
	// il calcolo del potenziale senza
	// controllo del parametro
	const TStroke *ref_;
	double range_; // range of mapping
	double par_;
	double actionLength_;  // lunghezza dell'azione
	double strokeLength_;  // lunghezza stroke
	double lenghtAtParam_; // lunghezza nel pto di movimento
	double leftFactor_;	// fattore di shape x la curva a sinistra
	double rightFactor_;   // fattore di shape x la curva a dx
};
}
#endif /* NOT_SIMMETRIC_BEZIER_POTENTIAL_H */
//-----------------------------------------------------------------------------
//  End Of File
//-----------------------------------------------------------------------------
