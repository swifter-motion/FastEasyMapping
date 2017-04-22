// For License please refer to LICENSE file in the root of FastEasyMapping project

#import <Foundation/Foundation.h>

@class FEMMapping, NSManagedObjectContext;

NS_ASSUME_NONNULL_BEGIN

typedef _Nonnull id<NSFastEnumeration> (^FEMObjectCacheSource)(FEMMapping *mapping);

@interface FEMObjectCache : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithSource:(FEMObjectCacheSource)source NS_DESIGNATED_INITIALIZER;

- (nullable id)objectForKey:(id)key mapping:(FEMMapping *)mapping;
- (void)setObject:(id)object forKey:(id)key mapping:(FEMMapping *)mapping;
- (NSDictionary *)objectsForMapping:(FEMMapping *)mapping;

@end

@interface FEMObjectCache (CoreData)

- (instancetype)initWithContext:(NSManagedObjectContext *)context
           presentedPrimaryKeys:(nullable NSMapTable<FEMMapping *, NSSet<id> *> *)presentedPrimaryKeys;

@end

NS_ASSUME_NONNULL_END
