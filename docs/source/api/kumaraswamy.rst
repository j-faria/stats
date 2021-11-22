.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Kumaraswamy Distribution
========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Kumaraswamy distribution:

.. math::

   f(x; a,b) = a b x^{a-1}{ (1-x^a)}^{b-1} \times \mathbf{1}[0 \leq x \leq 1]


Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dkumaraswamy-func-ref1:
.. doxygenfunction:: dkumaraswamy(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dkumaraswamy-func-ref2:
.. doxygenfunction:: dkumaraswamy(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dkumaraswamy-func-ref3:
.. doxygenfunction:: dkumaraswamy(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dkumaraswamy-func-ref4:
.. doxygenfunction:: dkumaraswamy(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dkumaraswamy-func-ref5:
.. doxygenfunction:: dkumaraswamy(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Kumaraswamy distribution:

.. math::

   F(x; a, b) = \int_0^x f(z; a,b) dz = 1 - (1 - x^a)^b

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pkumaraswamy-func-ref1:
.. doxygenfunction:: pkumaraswamy(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pkumaraswamy-func-ref2:
.. doxygenfunction:: pkumaraswamy(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _pkumaraswamy-func-ref3:
.. doxygenfunction:: pkumaraswamy(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _pkumaraswamy-func-ref4:
.. doxygenfunction:: pkumaraswamy(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _pkumaraswamy-func-ref5:
.. doxygenfunction:: pkumaraswamy(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Kumaraswamy distribution:

.. math::

   q(p; a,b) = (1 - (1 - y)^\frac{1}{b})^\frac{1}{a}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qkumaraswamy-func-ref1:
.. doxygenfunction:: qkumaraswamy(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qkumaraswamy-func-ref2:
.. doxygenfunction:: qkumaraswamy(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qkumaraswamy-func-ref3:
.. doxygenfunction:: qkumaraswamy(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qkumaraswamy-func-ref4:
.. doxygenfunction:: qkumaraswamy(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qkumaraswamy-func-ref5:
.. doxygenfunction:: qkumaraswamy(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Kumaraswamy distribution is achieved by inverse transform sampling.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rkumaraswamy-func-ref1:
.. doxygenfunction:: rkumaraswamy(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rkumaraswamy-func-ref2:
.. doxygenfunction:: rkumaraswamy(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rkumaraswamy-func-ref3:
.. doxygenfunction:: rkumaraswamy(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
