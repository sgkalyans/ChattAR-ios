//
//  AugmentedRealityController.h
//  MashApp-location_users-ar-ios
//
//  Created by QuickBlox developers on 3/26/12.
//  Copyright (c) 2012 QuickBlox. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreVideo/CoreVideo.h>
//#import "UserAnnotation.h"

@class ARCoordinate;

@interface ARViewController : UIViewController <UIAccelerometerDelegate, CLLocationManagerDelegate, AVCaptureVideoDataOutputSampleBufferDelegate, UIActionSheetDelegate> {
@private
	NSMutableArray		*coordinates;
    
    CGRect viewFrame;
	int switchedDistance;
    
    NSMutableArray *sliderNumbers;
}

@property (nonatomic, assign) BOOL scaleViewsBasedOnDistance;
@property (nonatomic, assign) BOOL transparenViewsBasedOnDistance;
@property (nonatomic, assign) BOOL rotateViewsBasedOnPerspective;
@property (nonatomic, assign) BOOL isFirstUpdateLocation;

@property (nonatomic, assign) double maximumScaleDistance;
@property (nonatomic, assign) double minimumScaleFactor;
@property (nonatomic, assign) double maximumRotationAngle;
@property (nonatomic, assign) double degreeRange;
@property (nonatomic, assign) double latestHeading;
@property (nonatomic, assign) float  viewAngle;

@property (nonatomic, retain) NSMutableArray *coordinates;
@property (retain) NSMutableArray *coordinateViews;

@property (nonatomic, retain) UIAccelerometer         *accelerometerManager;
@property (nonatomic, retain) CLLocationManager       *locationManager;
@property (nonatomic, retain) ARCoordinate            *centerCoordinate;
@property (nonatomic, retain) CLLocation              *centerLocation;
@property (nonatomic, retain) UIImageView             *displayView;
@property (nonatomic, assign) UIDeviceOrientation	  currentOrientation;

@property (nonatomic, retain) QBCOCustomObject        *chatRoom;

@property (nonatomic, assign) id delegate;

@property (nonatomic, assign) UISlider* distanceSlider;
@property (nonatomic, assign) UILabel* distanceLabel;

/*!
 @brief	The capture session takes the input from the camera and capture it
 */
@property (nonatomic, retain) AVCaptureSession *captureSession;

- (IBAction) initCapture;

- (id)initialize;

- (void)displayAR;
- (void)dissmisAR;

- (void)updateLocations;
- (void)updateMarkersPositionsForCenterLocation:(CLLocation *)_centerLocation;

// points
- (void)refreshWithNewPoints:(NSArray *)mapPoints;
- (void)addPoints:(NSArray *)mapPoints;
- (void)addPoint:(QBCOCustomObject *)point;

- (void)clear;


- (UIView *)viewForAnnotation:(QBCOCustomObject *)annotation;
//- (UIView *)viewForExistAnnotation:(QBCOCustomObject *)userAnnotation;

// Adding coordinates to the underlying data model.
- (void)addCoordinate:(ARCoordinate *)coordinate augmentedView:(UIView *)agView animated:(BOOL)animated ;

// Removing coordinates
- (void)removeCoordinate:(ARCoordinate *)coordinate;
- (void)removeCoordinate:(ARCoordinate *)coordinate animated:(BOOL)animated;
- (void)removeCoordinates:(NSArray *)coordinateArray;

- (IBAction)distanceDidChanged:(id)sender;

@end
