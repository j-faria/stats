.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Reciprocal Distribution
=======================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Reciprocal distribution:

.. math::

   f(x; a, b) = \frac{1}{x [\log(b) - \log(a)]} \times \mathbf{1}[ a \leq x \leq b]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dreciprocal-func-ref1:
.. doxygenfunction:: dreciprocal(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dreciprocal-func-ref2:
.. doxygenfunction:: dreciprocal(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dreciprocal-func-ref3:
.. doxygenfunction:: dreciprocal(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dreciprocal-func-ref4:
.. doxygenfunction:: dreciprocal(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dreciprocal-func-ref5:
.. doxygenfunction:: dreciprocal(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Reciprocal distribution:

.. math::

   F(x; a, b) = \int_{a}^x f(z; a, b) dz = \frac{\log(x) - \log(a)}{\log(b) - \log(a)} \times \mathbf{1}[ a \leq x \leq b]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _preciprocal-func-ref1:
.. doxygenfunction:: preciprocal(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _preciprocal-func-ref2:
.. doxygenfunction:: preciprocal(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _preciprocal-func-ref3:
.. doxygenfunction:: preciprocal(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _preciprocal-func-ref4:
.. doxygenfunction:: preciprocal(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _preciprocal-func-ref5:
.. doxygenfunction:: preciprocal(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Reciprocal distribution:

.. math::

   q(p; a, b) = a * \frac{b}{a}^p

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qreciprocal-func-ref1:
.. doxygenfunction:: qreciprocal(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qreciprocal-func-ref2:
.. doxygenfunction:: qreciprocal(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qreciprocal-func-ref3:
.. doxygenfunction:: qreciprocal(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qreciprocal-func-ref4:
.. doxygenfunction:: qreciprocal(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qreciprocal-func-ref5:
.. doxygenfunction:: qreciprocal(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Reciprocal distribution is achieved by inverse transform sampling.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rreciprocal-func-ref1:
.. doxygenfunction:: rreciprocal(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rreciprocal-func-ref2:
.. doxygenfunction:: rreciprocal(const T1, const T2, const ullint_t)
   :project: statslib

.. _rreciprocal-func-ref3:
.. doxygenfunction:: rreciprocal()
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rreciprocal-func-ref4:
.. doxygenfunction:: rreciprocal(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
