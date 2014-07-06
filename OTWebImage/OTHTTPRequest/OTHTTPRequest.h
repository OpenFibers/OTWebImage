//
//  OTHTTPRequest.h
//  OTHTTPRequestDemo
//
//  Created by openthread on 5/13/13.
//  Copyright (c) 2013 openthread. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OTHTTPRequest;

@interface NSMutableURLRequest (GetAndPostParams)

- (void)setUpGetParams:(NSDictionary *)dictionary;
- (void)setUpPostParams:(NSDictionary *)dictionary;

@end


@protocol OTHTTPRequestDelegate <NSObject>

@required
- (void)otHTTPRequestFinished:(OTHTTPRequest *)request;
- (void)otHTTPRequestFailed:(OTHTTPRequest *)request error:(NSError *)error;

@optional
- (void)otHTTPRequest:(OTHTTPRequest *)request dataUpdated:(NSData *)data;

@end

@interface OTHTTPRequest : NSObject

#pragma mark - Class Methods

+ (NSString *)urlEncode:(NSString *)stringToEncode;//Encode with UTF8
+ (NSString *)urlEncode:(NSString *)stringToEncode usingEncoding:(NSStringEncoding)encoding;

+ (NSString*)urlDecode:(NSString *)stringToDecode;//Decode with UTF8
+ (NSString*)urlDecode:(NSString *)stringToDecode usingEncoding:(NSStringEncoding)encoding;

+ (NSDictionary *)parseGetParamsFromURLString:(NSString *)urlString;

#pragma mark - Init Methods

//Create request with a NSURLRequest.
- (id)initWithNSURLRequest:(NSURLRequest *)request;

@property (nonatomic, assign) id<OTHTTPRequestDelegate> delegate;
@property (nonatomic, retain) id userInfo;

#pragma mark - Options

//Set if this is a low priority request. Set this property before call `start` to take effect.
//Default value is `YES`.
//When set to `NO`, request will be started at default priority.
@property (nonatomic,assign) BOOL isLowPriority;

//To avoid memory issues, default is YES.
@property (nonatomic, assign) BOOL shouldClearCachedResponseWhenRequestDone;

#pragma mark - Request and response

@property (nonatomic,readonly) NSURLRequest *request;

//Returns nil if response haven't reached yet.
@property (nonatomic,readonly) NSURLResponse *response;

//Returns 0 if http url response haven't reached yet.
@property (nonatomic, readonly) NSInteger responseStatusCode;

//Get responsed data
- (NSData *)responseData;

//Get responsed string using response's encoding. If response has no encoding info, use UTF8 encoding.
- (NSString *)responseString;

//Get responsed string using UTF8 encoding.
- (NSString *)responseUTF8String;

#pragma mark - Start and cancel

//cancel request
- (void)cancel;

//begin request
- (void)start;

@end
