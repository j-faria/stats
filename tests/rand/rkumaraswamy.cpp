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

#include "../stats_tests.hpp"

int main()
{
    print_begin("rkumaraswamy");

    //

    double a = 3;
    double b = 2;

    double _num = b * stmath::tgamma(1+1/a) * stmath::tgamma(b);
    double _den = stmath::tgamma(1 + 1/a + b);
    double k_mean = _num / _den;
    // calculation of variance is somewhat complicated...
    double k_var = 0.03673469387755074;

    int n_sample = 10000;

    //

    double k_rand = stats::rkumaraswamy(a, b);
    std::cout << "kumaraswamy rv draw: " << k_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> k_stdvec = stats::rkumaraswamy<std::vector<double>>(n_sample,1,a,b);

    std::cout << "stdvec: kumaraswamy rv mean: " << stats::mat_ops::mean(k_stdvec) << ". Should be close to: " << k_mean << "\n";
    std::cout << "stdvec: kumaraswamy rv variance: " << stats::mat_ops::var(k_stdvec) << ". Should be close to: " << k_var << std::endl;
#endif

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj k_vec = stats::rkumaraswamy<mat_obj>(n_sample,1,a,b);

    std::cout << "kumaraswamy rv mean: " << stats::mat_ops::mean(k_vec) << ". Should be close to: " << k_mean << std::endl;
    std::cout << "kumaraswamy rv variance: " << stats::mat_ops::var(k_vec) << ". Should be close to: " << k_var << std::endl;
#endif

    //

    std::cout << "\n*** rkumaraswamy: end tests. ***\n" << std::endl;
    
    return 0;
}
