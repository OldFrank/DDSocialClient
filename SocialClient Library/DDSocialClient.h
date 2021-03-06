//
//  DDSocialClient.h
//  SocialNetworkClient
//
//  Created by Damien DeVille on 7/27/10.
//  Copyright 2010 Snappy Code. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DDSocialClientLogin.h"
#import "OAuthToken.h"
#import "Reachability.h"

// ---------------------------------------------------------------------------------------------------
/*
	NOTE: You will need to change these ones to
	match your application details.
 */
#define FACEBOOK_API_ID			@""

#define TWITTER_API_KEY			@""
#define TWITTER_CONSUMER_KEY	@""
#define TWITTER_CONSUMER_SECRET	@""

#define BIT_LY_LOGIN			@""
#define BIT_LY_API_KEY			@""

#define TWITPIC_API_KEY			@""

#define FLICKR_API_KEY			@""
#define FLICKR_API_SECRET		@""

#define LINKEDIN_API_KEY		@""
#define LINKEDIN_API_SECRET		@""

#define FOURSQUARE_API_KEY		@""
#define FOURSQUARE_API_SECRET	@""
#define FOURSQUARE_CALLBACK		@""

// ---------------------------------------------------------------------------------------------------

typedef enum
{
	kDDSocialClientUnknown,
	kDDSocialClientFacebook,
	kDDSocialClientTwitter,
	kDDSocialClientFlickr,
	kDDSocialClientLinkedIn,
	kDDSocialClientFoursquare,
}
DDSocialClientType ;

#define FACEBOOK_DOMAIN			@"facebook.com"
#define TWITTER_DOMAIN			@"twitter.com"
#define FLICKR_DOMAIN			@"flickr.com"
#define LINKEDIN_DOMAIN			@"linkedin.com"
#define FOURSQUARE_DOMAIN		@"foursquare.com"

#define FACEBOOK_SERVICE_KEY	@"Facebook"
#define TWITTER_SERVICE_KEY		@"Twitter"
#define FLICKR_SERVICE_KEY		@"Flickr"
#define LINKEDIN_SERVICE_KEY	@"LinkedIn"
#define FOURSQUARE_SERVICE_KEY	@"Foursquare"


#define DDAuthenticationError	@"DDAuthenticationError"
/*
	Error codes:
		0 = unknown error
		1 = no connection
		2 = the request timed out
		3 = login page could not be displayed (user not implementing delegate)
		4 = the user cancelled by closing the login page
		5 = initial token request failed
		6 = OAuth token request failed
		7 = unspecified API key
 */

#define DDSocialClientError		@"DDSocialClientError"
/*
	Error codes:
		0 = unknown error
		1 = no connection
		2 = the request timed out
		3 = misconstructed post or request
		4 = social client error
 */


@protocol DDSocialClientDelegate ;

@interface DDSocialClient : NSObject <DDSocialClientLoginDelegate>
{
	id delegate ;
	OAuthToken *token ;
	DDSocialClientLogin *loginDialog ;
}

@property (nonatomic,assign) id <DDSocialClientDelegate> delegate ;
@property (nonatomic,retain) OAuthToken *token ;

- (id)initWithDelegate:(id<DDSocialClientDelegate>)aDelegate ;
- (DDSocialClientType)clientType ;
+ (NSString *)clientServiceKey ;
+ (NSString *)clientDomain ;
- (NSString *)name ;

// OAuth authentication related methods
+ (BOOL)serviceHasValidToken ;
- (BOOL)serviceHasValidToken ;
- (void)login ;
+ (void)logout ;

- (NSString *)authenticationURLString ;
- (void)showLoginDialog ;

@end


@protocol DDSocialClientDelegate <NSObject>

@optional
- (BOOL)shouldDisplayLoginForSocialClient:(DDSocialClient *)client ;
- (void)didDismissLoginForSocialClient:(DDSocialClient *)client ;

- (void)socialClientAuthenticationDidSucceed:(DDSocialClient *)client ;
- (void)socialClient:(DDSocialClient *)client authenticationDidFailWithError:(NSError *)error ;

@end