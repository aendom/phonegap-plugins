//
//  InAppPurchaseManager.h
//  beetight
//
//  Created by Matt Kane on 20/02/2011.
//  Copyright 2011 Matt Kane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "PhoneGapCommand.h"
#import "NSData+Base64.h"

#import "SKProduct+LocalizedPrice.h"

@interface InAppPurchaseManager : PhoneGapCommand <SKPaymentTransactionObserver> {

}
- (void) setup:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) makePurchase:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) requestProductData:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions;

@end

@interface ProductsRequestDelegate : NSObject <SKProductsRequestDelegate>{
	NSString* successCallback;
	NSString* failCallback;

	InAppPurchaseManager* command;
}

@property (nonatomic, copy) NSString* successCallback;
@property (nonatomic, copy) NSString* failCallback;
@property (nonatomic, retain) InAppPurchaseManager* command;

@end;

