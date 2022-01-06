/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 17.12
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HMISC
#define HCPP_HMISC

namespace HalconCpp
{

// Class grouping methods belonging to no other HALCON class.
class LIntExport HMisc
{

public:




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Write a tuple to a file.
  static void WriteTuple(const HTuple& Tuple, const HString& FileName);

  // Write a tuple to a file.
  static void WriteTuple(double Tuple, const HString& FileName);

  // Write a tuple to a file.
  static void WriteTuple(double Tuple, const char* FileName);

  // Read a tuple from a file.
  static HTuple ReadTuple(const HString& FileName);

  // Read a tuple from a file.
  static HTuple ReadTuple(const char* FileName);

  // Close all serial devices.
  static void CloseAllSerials();

  // Clear all OCV tools.
  static void CloseAllOcvs();

  // Destroy all OCR classifiers.
  static void CloseAllOcrs();

  // Concat training files.
  static void ConcatOcrTrainf(const HTuple& SingleFiles, const HString& ComposedFile);

  // Concat training files.
  static void ConcatOcrTrainf(const HString& SingleFiles, const HString& ComposedFile);

  // Concat training files.
  static void ConcatOcrTrainf(const char* SingleFiles, const char* ComposedFile);

  // Query which characters are stored in a (protected) training file.
  static HTuple ReadOcrTrainfNamesProtected(const HTuple& TrainingFile, const HTuple& Password, HTuple* CharacterCount);

  // Query which characters are stored in a (protected) training file.
  static HString ReadOcrTrainfNamesProtected(const HString& TrainingFile, const HString& Password, Hlong* CharacterCount);

  // Query which characters are stored in a (protected) training file.
  static HString ReadOcrTrainfNamesProtected(const char* TrainingFile, const char* Password, Hlong* CharacterCount);

  // Query which characters are stored in a training file.
  static HTuple ReadOcrTrainfNames(const HTuple& TrainingFile, HTuple* CharacterCount);

  // Query which characters are stored in a training file.
  static HString ReadOcrTrainfNames(const HString& TrainingFile, Hlong* CharacterCount);

  // Query which characters are stored in a training file.
  static HString ReadOcrTrainfNames(const char* TrainingFile, Hlong* CharacterCount);

  // Delete all measure objects.
  static void CloseAllMeasures();

  // Convert spherical coordinates of a 3D point to Cartesian coordinates.
  static void ConvertPoint3dSpherToCart(const HTuple& Longitude, const HTuple& Latitude, const HTuple& Radius, const HString& EquatPlaneNormal, const HString& ZeroMeridian, HTuple* X, HTuple* Y, HTuple* Z);

  // Convert spherical coordinates of a 3D point to Cartesian coordinates.
  static void ConvertPoint3dSpherToCart(double Longitude, double Latitude, double Radius, const HString& EquatPlaneNormal, const HString& ZeroMeridian, double* X, double* Y, double* Z);

  // Convert spherical coordinates of a 3D point to Cartesian coordinates.
  static void ConvertPoint3dSpherToCart(double Longitude, double Latitude, double Radius, const char* EquatPlaneNormal, const char* ZeroMeridian, double* X, double* Y, double* Z);

  // Convert Cartesian coordinates of a 3D point to spherical coordinates.
  static HTuple ConvertPoint3dCartToSpher(const HTuple& X, const HTuple& Y, const HTuple& Z, const HString& EquatPlaneNormal, const HString& ZeroMeridian, HTuple* Latitude, HTuple* Radius);

  // Convert Cartesian coordinates of a 3D point to spherical coordinates.
  static double ConvertPoint3dCartToSpher(double X, double Y, double Z, const HString& EquatPlaneNormal, const HString& ZeroMeridian, double* Latitude, double* Radius);

  // Convert Cartesian coordinates of a 3D point to spherical coordinates.
  static double ConvertPoint3dCartToSpher(double X, double Y, double Z, const char* EquatPlaneNormal, const char* ZeroMeridian, double* Latitude, double* Radius);

  // Read the description file of a Kalman filter.
  static HTuple ReadKalman(const HString& FileName, HTuple* Model, HTuple* Measurement, HTuple* Prediction);

  // Read the description file of a Kalman filter.
  static HTuple ReadKalman(const char* FileName, HTuple* Model, HTuple* Measurement, HTuple* Prediction);

  // Read an update file of a Kalman filter.
  static HTuple UpdateKalman(const HString& FileName, const HTuple& DimensionIn, const HTuple& ModelIn, const HTuple& MeasurementIn, HTuple* ModelOut, HTuple* MeasurementOut);

  // Read an update file of a Kalman filter.
  static HTuple UpdateKalman(const char* FileName, const HTuple& DimensionIn, const HTuple& ModelIn, const HTuple& MeasurementIn, HTuple* ModelOut, HTuple* MeasurementOut);

  // Estimate the current state of a system with the help of the Kalman filtering.
  static HTuple FilterKalman(const HTuple& Dimension, const HTuple& Model, const HTuple& Measurement, const HTuple& PredictionIn, HTuple* Estimate);

  // Generate a PostScript file, which describes the rectification grid.
  static void CreateRectificationGrid(double Width, Hlong NumSquares, const HString& GridFile);

  // Generate a PostScript file, which describes the rectification grid.
  static void CreateRectificationGrid(double Width, Hlong NumSquares, const char* GridFile);

  // Generate a projection map that describes the mapping between an arbitrarily distorted image and the rectified image.
  static HImage GenArbitraryDistortionMap(Hlong GridSpacing, const HTuple& Row, const HTuple& Column, Hlong GridWidth, Hlong ImageWidth, Hlong ImageHeight, const HString& MapType);

  // Generate a projection map that describes the mapping between an arbitrarily distorted image and the rectified image.
  static HImage GenArbitraryDistortionMap(Hlong GridSpacing, const HTuple& Row, const HTuple& Column, Hlong GridWidth, Hlong ImageWidth, Hlong ImageHeight, const char* MapType);

  // Calculate the projection of a point onto a line.
  static void ProjectionPl(const HTuple& Row, const HTuple& Column, const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2, HTuple* RowProj, HTuple* ColProj);

  // Calculate the projection of a point onto a line.
  static void ProjectionPl(double Row, double Column, double Row1, double Column1, double Row2, double Column2, double* RowProj, double* ColProj);

  // Calculate a point of an ellipse corresponding to a specific angle.
  static void GetPointsEllipse(const HTuple& Angle, double Row, double Column, double Phi, double Radius1, double Radius2, HTuple* RowPoint, HTuple* ColPoint);

  // Calculate a point of an ellipse corresponding to a specific angle.
  static void GetPointsEllipse(double Angle, double Row, double Column, double Phi, double Radius1, double Radius2, double* RowPoint, double* ColPoint);

  // Calculate the intersection point of two lines.
  static void IntersectionLl(const HTuple& RowA1, const HTuple& ColumnA1, const HTuple& RowA2, const HTuple& ColumnA2, const HTuple& RowB1, const HTuple& ColumnB1, const HTuple& RowB2, const HTuple& ColumnB2, HTuple* Row, HTuple* Column, HTuple* IsParallel);

  // Calculate the intersection point of two lines.
  static void IntersectionLl(double RowA1, double ColumnA1, double RowA2, double ColumnA2, double RowB1, double ColumnB1, double RowB2, double ColumnB2, double* Row, double* Column, Hlong* IsParallel);

  // Calculate the angle between one line and the horizontal axis.
  static HTuple AngleLx(const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2);

  // Calculate the angle between one line and the horizontal axis.
  static double AngleLx(double Row1, double Column1, double Row2, double Column2);

  // Calculate the angle between two lines.
  static HTuple AngleLl(const HTuple& RowA1, const HTuple& ColumnA1, const HTuple& RowA2, const HTuple& ColumnA2, const HTuple& RowB1, const HTuple& ColumnB1, const HTuple& RowB2, const HTuple& ColumnB2);

  // Calculate the angle between two lines.
  static double AngleLl(double RowA1, double ColumnA1, double RowA2, double ColumnA2, double RowB1, double ColumnB1, double RowB2, double ColumnB2);

  // Calculate the distances between a line segment and a line.
  static void DistanceSl(const HTuple& RowA1, const HTuple& ColumnA1, const HTuple& RowA2, const HTuple& ColumnA2, const HTuple& RowB1, const HTuple& ColumnB1, const HTuple& RowB2, const HTuple& ColumnB2, HTuple* DistanceMin, HTuple* DistanceMax);

  // Calculate the distances between a line segment and a line.
  static void DistanceSl(double RowA1, double ColumnA1, double RowA2, double ColumnA2, double RowB1, double ColumnB1, double RowB2, double ColumnB2, double* DistanceMin, double* DistanceMax);

  // Calculate the distances between two line segments.
  static void DistanceSs(const HTuple& RowA1, const HTuple& ColumnA1, const HTuple& RowA2, const HTuple& ColumnA2, const HTuple& RowB1, const HTuple& ColumnB1, const HTuple& RowB2, const HTuple& ColumnB2, HTuple* DistanceMin, HTuple* DistanceMax);

  // Calculate the distances between two line segments.
  static void DistanceSs(double RowA1, double ColumnA1, double RowA2, double ColumnA2, double RowB1, double ColumnB1, double RowB2, double ColumnB2, double* DistanceMin, double* DistanceMax);

  // Calculate the distances between a point and a line segment.
  static void DistancePs(const HTuple& Row, const HTuple& Column, const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2, HTuple* DistanceMin, HTuple* DistanceMax);

  // Calculate the distances between a point and a line segment.
  static void DistancePs(double Row, double Column, double Row1, double Column1, double Row2, double Column2, double* DistanceMin, double* DistanceMax);

  // Calculate the distance between one point and one line.
  static HTuple DistancePl(const HTuple& Row, const HTuple& Column, const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2);

  // Calculate the distance between one point and one line.
  static double DistancePl(double Row, double Column, double Row1, double Column1, double Row2, double Column2);

  // Calculate the distance between two points.
  static HTuple DistancePp(const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2);

  // Calculate the distance between two points.
  static double DistancePp(double Row1, double Column1, double Row2, double Column2);

  // Information on smoothing filter smooth_image.
  static Hlong InfoSmooth(const HString& Filter, double Alpha, HTuple* Coeffs);

  // Information on smoothing filter smooth_image.
  static Hlong InfoSmooth(const char* Filter, double Alpha, HTuple* Coeffs);

  // Generate a Gaussian noise distribution.
  static HTuple GaussDistribution(double Sigma);

  // Generate a salt-and-pepper noise distribution.
  static HTuple SpDistribution(const HTuple& PercentSalt, const HTuple& PercentPepper);

  // Generate a salt-and-pepper noise distribution.
  static HTuple SpDistribution(double PercentSalt, double PercentPepper);

  // Deserialize FFT speed optimization data.
  static void DeserializeFftOptimizationData(const HSerializedItem& SerializedItemHandle);

  // Serialize FFT speed optimization data.
  static HSerializedItem SerializeFftOptimizationData();

  // Load FFT speed optimization data from a file.
  static void ReadFftOptimizationData(const HString& FileName);

  // Load FFT speed optimization data from a file.
  static void ReadFftOptimizationData(const char* FileName);

  // Store FFT speed optimization data in a file.
  static void WriteFftOptimizationData(const HString& FileName);

  // Store FFT speed optimization data in a file.
  static void WriteFftOptimizationData(const char* FileName);

  // Optimize the runtime of the real-valued FFT.
  static void OptimizeRftSpeed(Hlong Width, Hlong Height, const HString& Mode);

  // Optimize the runtime of the real-valued FFT.
  static void OptimizeRftSpeed(Hlong Width, Hlong Height, const char* Mode);

  // Optimize the runtime of the FFT.
  static void OptimizeFftSpeed(Hlong Width, Hlong Height, const HString& Mode);

  // Optimize the runtime of the FFT.
  static void OptimizeFftSpeed(Hlong Width, Hlong Height, const char* Mode);

  // Estimate the width of a filter in edges_image.
  static Hlong InfoEdges(const HString& Filter, const HString& Mode, double Alpha, HTuple* Coeffs);

  // Estimate the width of a filter in edges_image.
  static Hlong InfoEdges(const char* Filter, const char* Mode, double Alpha, HTuple* Coeffs);

  // Copy a file to a new location.
  static void CopyFile(const HString& SourceFile, const HString& DestinationFile);

  // Copy a file to a new location.
  static void CopyFile(const char* SourceFile, const char* DestinationFile);

  // Set the current working directory.
  static void SetCurrentDir(const HString& DirName);

  // Set the current working directory.
  static void SetCurrentDir(const char* DirName);

  // Get the current working directory.
  static HString GetCurrentDir();

  // Delete an empty directory.
  static void RemoveDir(const HString& DirName);

  // Delete an empty directory.
  static void RemoveDir(const char* DirName);

  // Make a directory.
  static void MakeDir(const HString& DirName);

  // Make a directory.
  static void MakeDir(const char* DirName);

  // List all files in a directory.
  static HTuple ListFiles(const HString& Directory, const HTuple& Options);

  // List all files in a directory.
  static HTuple ListFiles(const HString& Directory, const HString& Options);

  // List all files in a directory.
  static HTuple ListFiles(const char* Directory, const char* Options);

  // Delete a file.
  static void DeleteFile(const HString& FileName);

  // Delete a file.
  static void DeleteFile(const char* FileName);

  // Check whether file exists.
  static Hlong FileExists(const HString& FileName);

  // Check whether file exists.
  static Hlong FileExists(const char* FileName);

  // Close all open files.
  static void CloseAllFiles();

  // Select the longest input lines.
  static void SelectLinesLongest(const HTuple& RowBeginIn, const HTuple& ColBeginIn, const HTuple& RowEndIn, const HTuple& ColEndIn, Hlong Num, HTuple* RowBeginOut, HTuple* ColBeginOut, HTuple* RowEndOut, HTuple* ColEndOut);

  // Partition lines according to various criteria.
  static void PartitionLines(const HTuple& RowBeginIn, const HTuple& ColBeginIn, const HTuple& RowEndIn, const HTuple& ColEndIn, const HTuple& Feature, const HString& Operation, const HTuple& Min, const HTuple& Max, HTuple* RowBeginOut, HTuple* ColBeginOut, HTuple* RowEndOut, HTuple* ColEndOut, HTuple* FailRowBOut, HTuple* FailColBOut, HTuple* FailRowEOut, HTuple* FailColEOut);

  // Partition lines according to various criteria.
  static void PartitionLines(const HTuple& RowBeginIn, const HTuple& ColBeginIn, const HTuple& RowEndIn, const HTuple& ColEndIn, const HString& Feature, const HString& Operation, const HString& Min, const HString& Max, HTuple* RowBeginOut, HTuple* ColBeginOut, HTuple* RowEndOut, HTuple* ColEndOut, HTuple* FailRowBOut, HTuple* FailColBOut, HTuple* FailRowEOut, HTuple* FailColEOut);

  // Partition lines according to various criteria.
  static void PartitionLines(const HTuple& RowBeginIn, const HTuple& ColBeginIn, const HTuple& RowEndIn, const HTuple& ColEndIn, const char* Feature, const char* Operation, const char* Min, const char* Max, HTuple* RowBeginOut, HTuple* ColBeginOut, HTuple* RowEndOut, HTuple* ColEndOut, HTuple* FailRowBOut, HTuple* FailColBOut, HTuple* FailRowEOut, HTuple* FailColEOut);

  // Select lines according to various criteria.
  static void SelectLines(const HTuple& RowBeginIn, const HTuple& ColBeginIn, const HTuple& RowEndIn, const HTuple& ColEndIn, const HTuple& Feature, const HString& Operation, const HTuple& Min, const HTuple& Max, HTuple* RowBeginOut, HTuple* ColBeginOut, HTuple* RowEndOut, HTuple* ColEndOut);

  // Select lines according to various criteria.
  static void SelectLines(const HTuple& RowBeginIn, const HTuple& ColBeginIn, const HTuple& RowEndIn, const HTuple& ColEndIn, const HString& Feature, const HString& Operation, const HString& Min, const HString& Max, HTuple* RowBeginOut, HTuple* ColBeginOut, HTuple* RowEndOut, HTuple* ColEndOut);

  // Select lines according to various criteria.
  static void SelectLines(const HTuple& RowBeginIn, const HTuple& ColBeginIn, const HTuple& RowEndIn, const HTuple& ColEndIn, const char* Feature, const char* Operation, const char* Min, const char* Max, HTuple* RowBeginOut, HTuple* ColBeginOut, HTuple* RowEndOut, HTuple* ColEndOut);

  // Calculate the center of gravity, length, and orientation of a line.
  static void LinePosition(const HTuple& RowBegin, const HTuple& ColBegin, const HTuple& RowEnd, const HTuple& ColEnd, HTuple* RowCenter, HTuple* ColCenter, HTuple* Length, HTuple* Phi);

  // Calculate the center of gravity, length, and orientation of a line.
  static void LinePosition(Hlong RowBegin, Hlong ColBegin, Hlong RowEnd, Hlong ColEnd, double* RowCenter, double* ColCenter, double* Length, double* Phi);

  // Calculate the orientation of lines.
  static HTuple LineOrientation(const HTuple& RowBegin, const HTuple& ColBegin, const HTuple& RowEnd, const HTuple& ColEnd);

  // Calculate the orientation of lines.
  static double LineOrientation(double RowBegin, double ColBegin, double RowEnd, double ColEnd);

  // Approximate a contour by arcs and lines.
  static void ApproxChainSimple(const HTuple& Row, const HTuple& Column, HTuple* ArcCenterRow, HTuple* ArcCenterCol, HTuple* ArcAngle, HTuple* ArcBeginRow, HTuple* ArcBeginCol, HTuple* LineBeginRow, HTuple* LineBeginCol, HTuple* LineEndRow, HTuple* LineEndCol, HTuple* Order);

  // Approximate a contour by arcs and lines.
  static void ApproxChain(const HTuple& Row, const HTuple& Column, double MinWidthCoord, double MaxWidthCoord, double ThreshStart, double ThreshEnd, double ThreshStep, double MinWidthSmooth, double MaxWidthSmooth, Hlong MinWidthCurve, Hlong MaxWidthCurve, double Weight1, double Weight2, double Weight3, HTuple* ArcCenterRow, HTuple* ArcCenterCol, HTuple* ArcAngle, HTuple* ArcBeginRow, HTuple* ArcBeginCol, HTuple* LineBeginRow, HTuple* LineBeginCol, HTuple* LineEndRow, HTuple* LineEndCol, HTuple* Order);

  // Destroy all classifiers.
  static void CloseAllClassBox();

  // Generate a calibration plate description file and a corresponding PostScript file for a calibration plate with rectangularly arranged marks.
  static void GenCaltab(Hlong XNum, Hlong YNum, double MarkDist, double DiameterRatio, const HString& CalPlateDescr, const HString& CalPlatePSFile);

  // Generate a calibration plate description file and a corresponding PostScript file for a calibration plate with rectangularly arranged marks.
  static void GenCaltab(Hlong XNum, Hlong YNum, double MarkDist, double DiameterRatio, const char* CalPlateDescr, const char* CalPlatePSFile);

  // Generate a calibration plate description file and a corresponding PostScript file for a calibration plate with hexagonally arranged marks.
  static void CreateCaltab(Hlong NumRows, Hlong MarksPerRow, double Diameter, const HTuple& FinderRow, const HTuple& FinderColumn, const HString& Polarity, const HString& CalPlateDescr, const HString& CalPlatePSFile);

  // Generate a calibration plate description file and a corresponding PostScript file for a calibration plate with hexagonally arranged marks.
  static void CreateCaltab(Hlong NumRows, Hlong MarksPerRow, double Diameter, Hlong FinderRow, Hlong FinderColumn, const HString& Polarity, const HString& CalPlateDescr, const HString& CalPlatePSFile);

  // Generate a calibration plate description file and a corresponding PostScript file for a calibration plate with hexagonally arranged marks.
  static void CreateCaltab(Hlong NumRows, Hlong MarksPerRow, double Diameter, Hlong FinderRow, Hlong FinderColumn, const char* Polarity, const char* CalPlateDescr, const char* CalPlatePSFile);

  // Read the mark center points from the calibration plate description file.
  static void CaltabPoints(const HString& CalPlateDescr, HTuple* X, HTuple* Y, HTuple* Z);

  // Read the mark center points from the calibration plate description file.
  static void CaltabPoints(const char* CalPlateDescr, HTuple* X, HTuple* Y, HTuple* Z);

  // Delete all background estimation data sets.
  static void CloseAllBgEsti();

  // Close all image acquisition devices.
  static void CloseAllFramegrabbers();

};

}

#endif
