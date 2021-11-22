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
    print_begin("rreciprocal");

    //

    double a_par = 1;
    double b_par = 3;
    double q = log(b_par / a_par);

    double reciprocal_mean = (b_par - a_par) / q;
    double reciprocal_var = (b_par - a_par) * (b_par * (q - 2) + a_par * (q + 2)) / (2 * pow(q,2));

    int n_sample = 10000;

    //

    double reciprocal_rand = stats::rreciprocal(a_par,b_par);
    std::cout << "unif rv draw: " << reciprocal_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> reciprocal_stdvec = stats::rreciprocal<std::vector<double>>(n_sample,1,a_par,b_par);

    std::cout << "unif rv mean: " << stats::mat_ops::mean(reciprocal_stdvec) << ". Should be close to: " << reciprocal_mean << std::endl;
    std::cout << "unif rv variance: " << stats::mat_ops::var(reciprocal_stdvec) << ". Should be close to: " << reciprocal_var << std::endl;
#endif

    //

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj reciprocal_vec = stats::rreciprocal<mat_obj>(n_sample,1,a_par,b_par);

    std::cout << "unif rv mean: " << stats::mat_ops::mean(reciprocal_vec) << ". Should be close to: " << reciprocal_mean << std::endl;
    std::cout << "unif rv variance: " << stats::mat_ops::var(reciprocal_vec) << ". Should be close to: " << reciprocal_var << std::endl;
#endif
    
    //

    std::cout << "\n*** rreciprocal: end tests. ***\n" << std::endl;
    
    return 0;
}
