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
 * quantile function of the reciprocal distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
qreciprocal_compute(const T p, const T a_par, const T b_par)
noexcept
{
    return( a_par * stmath::pow(b_par / a_par, p) );
}

template<typename T>
statslib_constexpr
T
qreciprocal_vals_check(const T p, const T a_par, const T b_par)
noexcept
{
    return( !reciprocal_sanity_check(a_par,b_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            !prob_val_check(p) ? \
                STLIM<T>::quiet_NaN() :
            //
            GCINT::any_inf(a_par,b_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            p == T(0) ? \
                a_par :
            p == T(1) ? \
                b_par :
            //
            qreciprocal_compute(p,a_par,b_par) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
qreciprocal_type_check(const T1 p, const T2 a_par, const T3 b_par)
noexcept
{
    return qreciprocal_vals_check(static_cast<TC>(p),static_cast<TC>(a_par),static_cast<TC>(b_par));
}

}

/**
 * @brief Quantile function of the Reciprocal distribution
 *
 * @param p a real-valued input.
 * @param a_par the lower bound parameter, a real-valued input.
 * @param b_par the upper bound parameter, a real-valued input.
 *
 * @return the quantile function evaluated at \c p.
 * 
 * Example:
 * \code{.cpp} stats::qreciprocal(0.5,1.0,10.0); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
qreciprocal(const T1 p, const T2 a_par, const T3 b_par)
noexcept
{
    return internal::qreciprocal_type_check(p,a_par,b_par);
}

//
// vector/matrix input

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
void
qreciprocal_vec(const eT* __stats_pointer_settings__ vals_in, const T1 a_par, const T2 b_par, 
                rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qreciprocal,vals_in,vals_out,num_elem,a_par,b_par);
}
#endif

}

/**
 * @brief Quantile function of the Reciprocal distribution
 *
 * @param x a standard vector.
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 *
 * @return a vector of quantile values corresponding to the elements of \c x.
 * 
 * Example:
 * \code{.cpp}
 * std::vector<double> x = {0.3, 0.5, 0.9};
 * stats::qreciprocal(x,1.0,10.0);
 * \endcode
 */

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
std::vector<rT>
qreciprocal(const std::vector<eT>& x, const T1 a_par, const T2 b_par)
{
    STDVEC_DIST_FN(qreciprocal_vec,a_par,b_par);
}
#endif

/**
 * @brief Quantile function of the Reciprocal distribution
 *
 * @param X a matrix of input values.
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 *
 * @return a matrix of quantile values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {0.2,  0.7,  0.1},
 *                 {0.9,  0.3,  0.87} };
 * stats::qreciprocal(X,1.0,10.0);
 * \endcode
 */

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
ArmaMat<rT>
qreciprocal(const ArmaMat<eT>& X, const T1 a_par, const T2 b_par)
{
    ARMA_DIST_FN(qreciprocal_vec,a_par,b_par);
}

template<typename mT, typename tT, typename T1, typename T2>
statslib_inline
mT
qreciprocal(const ArmaGen<mT,tT>& X, const T1 a_par, const T2 b_par)
{
    return qreciprocal(X.eval(),a_par,b_par);
}
#endif

/**
 * @brief Quantile function of the Reciprocal distribution
 *
 * @param X a matrix of input values.
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 *
 * @return a matrix of quantile values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::qreciprocal(X,1.0,10.0);
 * \endcode
 */

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT, bool To>
statslib_inline
BlazeMat<rT,To>
qreciprocal(const BlazeMat<eT,To>& X, const T1 a_par, const T2 b_par)
{
    BLAZE_DIST_FN(qreciprocal_vec,a_par,b_par);
}
#endif

/**
 * @brief Quantile function of the Reciprocal distribution
 *
 * @param X a matrix of input values.
 * @param a_par a real-valued shape parameter.
 * @param b_par    a real-valued shape parameter.
 *
 * @return a matrix of quantile values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::qreciprocal(X,1.0,10.0);
 * \endcode
 */

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT, int iTr, int iTc>
statslib_inline
EigenMat<rT,iTr,iTc>
qreciprocal(const EigenMat<eT,iTr,iTc>& X, const T1 a_par, const T2 b_par)
{
    EIGEN_DIST_FN(qreciprocal_vec,a_par,b_par);
}
#endif
