#ifndef BDSInpainting_H
#define BDSInpainting_H

#include "itkCovariantVector.h"
#include "itkImage.h"
#include "itkImageRegion.h"
#include "itkVectorImage.h"

#include "Mask/Mask.h"

class BDSInpainting
{
public:

  BDSInpainting();

  typedef itk::Image<itk::CovariantVector<float, 3>, 2> ImageType;

  /** The main driver. */
  void Compute();

  /** This function does the actual work, and is called from Compute() at multiple resolutions. */
  void Compute(ImageType* const image, Mask* const mask, ImageType* const output);

  ImageType* GetOutput();

  void SetIterations(const unsigned int iterations);

  void SetPatchRadius(const unsigned int patchRadius);

  void SetResolutionLevels(const unsigned int resolutionLevels);

  void SetPatchMatchIterations(const unsigned int patchMatchIterations);
  
  void SetImage(ImageType* const image);

  void SetMask(Mask* const mask);

private:

  unsigned int ResolutionLevels;
  unsigned int Iterations;
  unsigned int PatchRadius;
  unsigned int PatchMatchIterations;

  ImageType::Pointer Output;

  ImageType::Pointer Image;

  Mask::Pointer MaskImage;

};

#endif


