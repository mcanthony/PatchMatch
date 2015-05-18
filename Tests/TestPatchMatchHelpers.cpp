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

/** This program computes the NN field of an image. */

// STL
#include <iostream>

// ITK
#include "itkImage.h"

// Submodules
#include "Mask/Mask.h"
#include "Mask/ITKHelpers/ITKHelpers.h"

// Custom
#include "PatchMatchHelpers.h"

// Helpers
template <typename TImage>
void OutputPixelsLinear(const TImage* const image);

int main(int, char*[])
{

  return EXIT_SUCCESS;
}

template <typename TImage>
void OutputPixelsLinear(const TImage* const image)
{
  itk::ImageRegionConstIterator<TImage> imageIterator(image, image->GetLargestPossibleRegion());

  while(!imageIterator.IsAtEnd())
  {
    std::cout << imageIterator.Get() << std::endl;
    ++imageIterator;
  }
}
