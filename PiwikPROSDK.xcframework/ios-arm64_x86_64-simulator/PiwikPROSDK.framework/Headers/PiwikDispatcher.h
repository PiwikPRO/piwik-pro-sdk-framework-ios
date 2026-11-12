//
//  PiwikDispatcher.h
//  PiwikTracker
//
//  Created by Mattias Levin on 29/08/14.
//  Copyright (c) 2014 Mattias Levin. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 The dispatcher is responsible for performing the actual network request to the Piwik server.

 Developers can provide their own dispatchers by implementing this protocol. This may be necessary if the app a require specific security schema, authentication, http client frameworks or network and server configurations.
 */
@protocol PiwikDispatcher <NSObject>

/**
 Send a single tracking event to the Piwik server.

 The dispatcher must send a GET request to the Piwik server, appending the parameters as a URL encoded query string.

 @param parameters Event parameters. These parameters should be added to the path as a URL encoded query string
 @param successBlock Run the block if the dispatch to the Piwik server is successful.
 @param failureBlock Run this block if the dispatch to the Piwik server fails. Provide a YES to indicate if the SDK should attempt to send any pending event or NO if pending events should be saved until next dispatch. E.g. there is no use trying to send pending events if there is no network connection.
 */
- (void)sendSingleEventWithParameters:(NSMutableArray *)parameters success:(void (^)(void))successBlock failure:(void (^)(BOOL shouldContinue))failureBlock;

/**
 Send a a bulk of tracking events to the Piwik server.

 The dispatcher must send a POST request to the Piwik server, adding the parameters as a JSON encoded body to the request.

 @param parameters Event parameters. These parameters should be JSON encoded and added to the request body.
 @param successBlock Run the block if the dispatch to the Piwik server is successful.
 @param failureBlock Run this block if the dispatch to the Piwik server fails. Provide a YES to indicate if the SDK should attempt to send any pending event or NO if pending events should be saved until next dispatch. E.g. there is no use trying to send pending events if there is no network connection.
 */
- (void)sendBulkEventWithParameters:(NSMutableArray *)parameters success:(void (^)(void))successBlock failure:(void (^)(BOOL shouldContinue))failureBlock;


@optional

/**
 Send a request to get Data Activation audience IDs from the Piwik server.

 @param visitorID Visitor ID.
 @param siteID Site ID.
 @param successBlock Run the block if the request to the Piwik server is successful.
 @param failureBlock Run this block if the request to the Piwik server fails.
 */
- (void)getDataActivationAudiencesWithVisitorID:(NSString *)visitorID siteID:(NSString *)siteID success:(void (^)(NSArray<NSString *> *audienceIDs))successBlock failure:(void (^)(NSError *error))failureBlock;

/**
 Send a request to get Data Activation profile attributes from the Piwik server.

 @param visitorID Visitor ID.
 @param siteID Site ID.
 @param successBlock Run the block if the request to the Piwik server is successful.
 @param failureBlock Run this block if the request to the Piwik server fails.
 */
- (void)getDataActivationProfileAttributesWithVisitorID:(NSString *)visitorID siteID:(NSString *)siteID success:(void (^)(NSDictionary<NSString *, id> *profileAttributes))successBlock failure:(void (^)(NSError *error))failureBlock;

/**
 Send a Data Activation profile update to the Piwik server.

 The dispatcher must send a POST request to the Data Activation update profile endpoint, adding the parameters as a JSON encoded body to the request. Requests rejected by Data Activation (HTTP 400, 402, 404 and 422) must be reported as successful, so that they are not retried.

 @param parameters Profile identifiers and attributes. These parameters should be JSON encoded and added to the request body.
 @param siteID Site ID.
 @param successBlock Run the block if the dispatch to the Piwik server is successful.
 @param failureBlock Run this block if the dispatch to the Piwik server fails. Provide a YES to indicate if the SDK should attempt to send any pending event or NO if pending events should be saved until next dispatch.
 */
- (void)sendDataActivationEventWithParameters:(NSDictionary *)parameters siteID:(NSString *)siteID success:(void (^)(void))successBlock failure:(void (^)(BOOL shouldContinue))failureBlock;

/**
 *  Set a custom user agent the dispatchers will use for requests.
 *
 *  @param userAgent The user agent string.
 */
- (void)setUserAgent:(NSString *)userAgent;

/**
 *  Get a custom user agent that dispatcher is using for building requests.
 */
- (NSString *)getUserAgent;

@end

NS_ASSUME_NONNULL_END
