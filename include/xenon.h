/**
 * \file
 * Xenon class definition. Xenon-129 is used as a comagnetometer used in the TRIUMF EDM experiment. 
 */

#ifndef XENON_H_
#define XENON_H_

#include "particle.h"

extern const char* NAME_XENON; ///< name of TXenon class

/**
 * Xenon particle class.
 *
 * Simulates a xenon atom including gravitation and Lorentz-force
 */
struct TXenon:TParticle{
public:
	/**
	 * Create xenon-129 atom. 
	 *
	 * Wraps basic TParticle constructor
	 *
	 * @param number Particle number
	 * @param t Starting time
	 * @param x Initial x coordinate
	 * @param y Initial y coordinate
	 * @param z Initial z coordinate
	 * @param E Initial kinetic energy
	 * @param phi Initial azimuth of velocity vector
	 * @param theta Initial polar angle of velocity vector
	 * @param polarisation polarisation (+/-1)
	 * @param amc Random number generator
	 * @param geometry Experiment geometry
	 * @param afield Optional fields (can be NULL)
	 */
	TXenon (int number, double t, double x, double y, double z, double E, double phi, double theta, double polarisation, TMCGenerator &amc, TGeometry &geometry, TFieldManager *afield);

protected:
	static std::ofstream endout; ///< endlog file stream
	static std::ofstream snapshotout; ///< snapshot file stream
	static std::ofstream trackout; ///< tracklog file stream
	static std::ofstream hitout; ///< hitlog file stream
	static std::ofstream spinout; ///< spinlog file stream
	
	/**
	 * This method is executed, when a particle encounters a material boundary.
	 * The atom is reflected specularly or diffusely depending on the material type. 
	 *
	 * @param x1 Start time of line segment
	 * @param y1 Start point of line segment
	 * @param x2 End time of line segment, set to x1 if reflection happened
	 * @param y2 End point of line segment, returns reflected velocity
	 * @param normal Normal vector of hit surface
	 * @param leaving Solid that the electron is leaving
	 * @param entering Solid that the electron is entering
	 * @param trajectoryaltered Returns true if the particle trajectory was altered
	 * @param traversed Returns true if the material boundary was traversed by the particle
	 */
	void OnHit(const value_type x1, const state_type &y1, value_type &x2, state_type &y2,
			const double normal[3], const solid &leaving, const solid &entering, bool &trajectoryaltered, bool &traversed);

	/**
	 * Reflect mercury-199 from surface.
	 *
	 * Reflects or scatters the neutron according to specular or Lambert.
	 */
	void Reflect(const value_type x1, const state_type &y1, value_type &x2, state_type &y2,
			const double normal[3], const solid &leaving, const solid &entering, bool &trajectoryaltered, bool &traversed);
	
	/**
	 * This method is executed on each step.
	 *
	 * Do nothing. 
	 *
	 * @param x1 Start time of line segment
	 * @param y1 Start point of line segment
	 * @param x2 End time of line segment, may be altered
	 * @param y2 End point of line segment, may be altered
	 * @param stepper Trajectory integrator, can be used to calculate intermediate state vectors
	 * @param currentsolid Solid in which the electron is at the moment
	 * @return Returns true if particle trajectory was altered
	 */
	bool OnStep(const value_type x1, const state_type &y1, value_type &x2, state_type &y2, const dense_stepper_type &stepper, const solid &currentsolid);


	/**
	 * Xenon decay (not used)
	 */
	void Decay();


	/**
	 * Return this particle type's log files
	 *
	 * @param str Enum specifying, which log file should be returned.
	 *
	 * @return log file
	 */
	std::ofstream& GetLogStream(const LogStream str) const{
		switch (str){
			case endLog: return endout;
			case snapshotLog: return snapshotout;
			case hitLog: return hitout;
			case trackLog: return trackout;
			case spinLog: return spinout;
		}
		throw std::out_of_range("Unknown LogStream requested!\n");
	};
};

#endif // XENON_H_
