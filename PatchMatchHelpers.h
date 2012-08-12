/*=========================================================================
 *
 *  Copyright David Doria 2012 daviddoria@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef PatchMatchHelpers_H
#define PatchMatchHelpers_H

// ITK
#include "itkImageRegionConstIterator.h"
#include "itkImage.h"
#include "itkCovariantVector.h"

// Custom
#include "Match.h"

namespace PatchMatchHelpers
{

itk::Offset<2> RandomNeighborNonZeroOffset();

//typedef itk::Image<itk::CovariantVector<float, 3>, 2> CoordinateImageType;
typedef itk::VectorImage<float, 2> CoordinateImageType;

typedef itk::Image<Match, 2> NNFieldType;

template <typename NNFieldType, typename CoordinateImageType>
void GetPatchCentersImage(const NNFieldType* const matchImage, CoordinateImageType* const output);


/** Get an image where the channels are (x component, y component, score) from the nearest
  * neighbor field struct. */
template <typename NNFieldType>
void WriteNNField(const NNFieldType* const nnField, const std::string& fileName);

/** Count how many pixels in the 'nnField' which are Valid in the 'mask' pass (return true) the testFunctor. */
template <typename NNFieldType, typename TTestFunctor>
unsigned int CountTestedPixels(const NNFieldType* const nnField, const Mask* const mask,
                               TTestFunctor testFunctor);

template <typename NNFieldType>
unsigned int CountInvalidPixels(const NNFieldType* const nnField, const Mask* const mask);

void WriteValidPixels(const NNFieldType* const nnField, const std::string& fileName);

} // end PatchMatchHelpers namespace

#include "PatchMatchHelpers.hpp"

#endif
