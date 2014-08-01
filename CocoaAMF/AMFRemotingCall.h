//
//  AMFRemotingCall.h
//  CocoaAMF
//
//  Created by Marc Bauer on 10.01.09.
//  Copyright 2009 nesiumdotcom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMF.h"
#import "AMFActionMessage.h"

#define kAMFRemotingCallErrorDomain @"AMFRemotingCallErrorDomain"
#define kAMFServerStatusCodeKey @"statusCode"

#define kAMFInvalidResponseErrorCode 1
#define kAMFServerErrorErrorCode 2

@protocol AMFRemotingCallDelegate;

@interface AMFRemotingCall : NSObject 
{
	NSURLConnection *m_connection;
	NSMutableURLRequest *m_request;
	NSString *m_service;
	NSString *m_method;
	NSObject *m_arguments;
	AMFVersion m_amfVersion;
	NSMutableData *m_receivedData;
	BOOL m_isLoading;
	NSError *m_error;
	NSObject <AMFRemotingCallDelegate> *m_delegate;
	NSMutableDictionary *m_amfHeaders;
    
    NSString * m_user;
    NSString * m_password;
}

@property (nonatomic, retain) NSURL *URL;
@property (nonatomic, retain) NSString *service;
@property (nonatomic, retain) NSString *method;
@property (nonatomic, retain) NSObject *arguments;
@property (nonatomic, retain) NSString *user;
@property (nonatomic, retain) NSString *password;
@property (nonatomic, assign) NSObject <AMFRemotingCallDelegate> *delegate;
@property (nonatomic, assign) AMFVersion amfVersion; // AMF3 is used by default
@property (nonatomic, assign) BOOL m_isLoading;

+ (AMFRemotingCall *)remotingCallWithURL:(NSURL *)url service:(NSString *)service 
	method:(NSString *)method arguments:(NSObject *)arguments;
- (id)initWithURL:(NSURL *)url service:(NSString *)service method:(NSString *)method 
	arguments:(NSObject *)arguments;
- (id)initWithURL:(NSURL *)url service:(NSString *)service method:(NSString *)method 
        arguments:(NSObject *)arguments user:(NSString *)user password:(NSString *)password;

- (void)start; // starts the request

- (void)addValue:(NSString *)value forHTTPHeaderField:(NSString *)field;
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;
- (NSString *)valueForHTTPHeaderField:(NSString *)field;
- (void)setValue:(NSObject *)value forAMFHeaderField:(NSString *)field 
	mustUnderstand:(BOOL)mustUnderstand;
@end


@protocol AMFRemotingCallDelegate

@optional
- (void)remotingCall:(AMFRemotingCall *)remotingCall didReceiveResponse:(NSURLResponse *)response;
- (void)remotingCall:(AMFRemotingCall *)remotingCall didReceiveData:(NSData *)data;
- (NSURLRequest *)remotingCall:(AMFRemotingCall *)remotingCall 
	willSendRequest:(NSURLRequest *)request redirectResponse:(NSURLResponse *)redirectResponse;
- (void)remotingCall:(AMFRemotingCall *)remotingCall didSendBodyData:(NSInteger)bytesWritten totalBytesWritten:(NSInteger)totalBytesWritten totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite;

@required
- (void)remotingCallDidFinishLoading:(AMFRemotingCall *)remotingCall 
	receivedObject:(NSObject *)object;
- (void)remotingCall:(AMFRemotingCall *)remotingCall didFailWithError:(NSError *)error;
@end