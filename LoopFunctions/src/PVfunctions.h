/* 
 * File:   PVfunctions.h
 * Author: mishima
 */

#ifndef PVFUNCTIONS_H
#define	PVFUNCTIONS_H

#include <gslpp_complex.h>

using namespace gslpp;

class PVfunctions {
public:

    PVfunctions();

    PVfunctions(const PVfunctions& orig);

    virtual ~PVfunctions();

    /**
     * @brief the scalar one-point Passarino-Veltman function
     * @param[in] mu renormalization scale
     * @param[in] m mass m
     * @return the finite part of the scalar one-point PV function at the scale mu
     */
    double A0(const double mu, const double m);
    
    /**
     * @brief the scalar two-point Passarino-Veltman function
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of the scalar two-point PV function at the scale mu
     */
    complex B0(const double mu, const double p2, 
               const double m0, const double m1); 
    
    /**
     * @brief the vector two-point Passarino-Veltman function
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of the vector two-point PV function at the scale mu
     */
    complex B1(const double mu, const double p2, 
               const double m0, const double m1); 
    
    /**
     * @brief a tensor two-point Passarino-Veltman function
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of a tensor two-point PV function B_{21} at the scale mu
     */
    complex B21(const double mu, const double p2, 
                const double m0, const double m1);     
    
    /**
     * @brief a tensor two-point Passarino-Veltman function
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of a tensor two-point PV function B_{22} at the scale mu
     */
    //complex B22(const double mu, const double p2, 
    //            const double m0, const double m1);       
    
    /**
     * @brief a sum of two-point Passarino-Veltman functions
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of a sum of two-point PV function at the scale mu
     */
    complex Bf(const double mu, const double p2, 
               const double m0, const double m1);       
    
    /**
     * @brief the derivative of B_0
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of B_{0p}
     */
    complex B0p(const double mu, const double p2, 
                const double m0, const double m1); 
    
    /**
     * @brief the derivative of B_1
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of B_{1p}
     */
    complex B1p(const double mu, const double p2, 
                const double m0, const double m1); 
    
    /**
     * @brief the derivative of B_{21}
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of B_{21p}
     */
    complex B21p(const double mu, const double p2, 
                 const double m0, const double m1);     
    
    /**
     * @brief the derivative of B_{22}
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of B_{22p}
     */
    //complex B22p(const double mu, const double p2, 
    //             const double m0, const double m1);       
    
    /**
     * @brief the derivative of B_{f}
     * @param[in] mu renormalization scale
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @return the finite part of B_{fp}
     */
    complex Bfp(const double mu, const double p2, 
                const double m0, const double m1);       
    
    /**
     * @brief the scalar three-point Passarino-Veltman function
     * @param[in] p2 p squared
     * @param[in] m0 mass m_0
     * @param[in] m1 mass m_1
     * @param[in] m2 mass m_2
     * @return the scalar three-point PV function 
     */
    complex C0(const double p2, 
               const double m0, const double m1, const double m2); 
    
private:

};

#endif	/* PVFUNCTIONS_H */

