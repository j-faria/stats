/*################################################################################
  ##
  ##   Copyright (C) 2011-2021 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

/* 
 * Sample from a Kumaraswamy distribution
 */

//
// scalar output

namespace internal
{

template<typename T>
statslib_inline
T
rkumaraswamy_compute(const T a_par, const T b_par, rand_engine_t& engine)
{
    if (!beta_sanity_check(a_par,b_par)) {
        return STLIM<T>::quiet_NaN();
    }

    //

    // inverse cdf sampling
    const T r = runif(T(0), T(1), engine);
    return qkumaraswamy(r, a_par, b_par);
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_inline
TC
rkumaraswamy_type_check(const T1 a_par, const T2 b_par, rand_engine_t& engine)
{
    return rkumaraswamy_compute(static_cast<TC>(a_par),static_cast<TC>(b_par),engine);
}

}

/**
 * @brief Random sampling function for the Kumaraswamy distribution
 *
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 * @param engine a random engine, passed by reference.
 *
 * @return a pseudo-random draw from the Kumaraswamy distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rand_engine_t engine(1776);
 * stats::rkumaraswamy(3.0,2.0,engine);
 * \endcode
 */

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2> 
rkumaraswamy(const T1 a_par, const T2 b_par, rand_engine_t& engine)
{
    return internal::rkumaraswamy_type_check(a_par,b_par,engine);
}

/**
 * @brief Random sampling function for the Kumaraswamy distribution
 *
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a pseudo-random draw from the Kumaraswamy distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rkumaraswamy(3.0,2.0,1776);
 * \endcode
 */

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2> 
rkumaraswamy(const T1 a_par, const T2 b_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rkumaraswamy(a_par,b_par,engine);
}

//
// vector/matrix output

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename T1, typename T2, typename rT>
statslib_inline
void
rkumaraswamy_vec(const T1 a_par, const T2 b_par, rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rkumaraswamy,vals_out,num_elem,a_par,b_par);
}
#endif

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2>
statslib_inline
void
rkumaraswamy_mat_check(std::vector<eT>& X, const T1 a_par, const T2 b_par)
{
    STDVEC_RAND_DIST_FN(rkumaraswamy,a_par,b_par);
}
#endif

#ifdef STATS_ENABLE_MATRIX_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
void
rkumaraswamy_mat_check(mT& X, const T1 a_par, const T2 b_par)
{
    MAIN_MAT_RAND_DIST_FN(rkumaraswamy,a_par,b_par);
}
#endif

}

/**
 * @brief Random matrix sampling function for the Kumaraswamy distribution
 *
 * @param n the number of output rows
 * @param k the number of output columns
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 *
 * @return a matrix of pseudo-random draws from the Kumaraswamy distribution.
 *
 * Example:
 * \code{.cpp}
 * // std::vector
 * stats::rkumaraswamy<std::vector<double>>(5,4,3.0,2.0);
 * // Armadillo matrix
 * stats::rkumaraswamy<arma::mat>(5,4,3.0,2.0);
 * // Blaze dynamic matrix
 * stats::rkumaraswamy<blaze::DynamicMatrix<double,blaze::columnMajor>>(5,4,3.0,2.0);
 * // Eigen dynamic matrix
 * stats::rkumaraswamy<Eigen::MatrixXd>(5,4,3.0,2.0);
 * \endcode
 *
 * @note This function requires template instantiation; acceptable output types include: <tt>std::vector</tt>, with element type \c float, \c double, etc., as well as Armadillo, Blaze, and Eigen dense matrices.
 */

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
mT
rkumaraswamy(const ullint_t n, const ullint_t k, const T1 a_par, const T2 b_par)
{
    GEN_MAT_RAND_FN(rkumaraswamy_mat_check,a_par,b_par);
}
#endif
