//
//  XDSwipeView.h
//  demo
//
//  Created by xiedong on 2017/4/25.
//  Copyright © 2017年 xiedong. All rights reserved.
//

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wauto-import"
#pragma GCC diagnostic ignored "-Wobjc-missing-property-synthesis"


#import <Availability.h>
#undef weak_delegate
#if __has_feature(objc_arc) && __has_feature(objc_arc_weak)
#define weak_delegate weak
#else
#define weak_delegate unsafe_unretained
#endif

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SwipeViewAlignment)
{
    SwipeViewAlignmentEdge = 0,
    SwipeViewAlignmentCenter
};

@protocol XDSwipeViewDataSource, XDSwipeViewDelegate;

@interface XDSwipeView : UIView

@property (nonatomic, weak_delegate) id<XDSwipeViewDataSource> dataSource;
@property (nonatomic, weak_delegate) id<XDSwipeViewDelegate> delegate;
@property (nonatomic, readonly) NSInteger numberOfItems;
@property (nonatomic, readonly) NSInteger numberOfPages;
@property (nonatomic, readonly) CGSize itemSize;
@property (nonatomic, assign) NSInteger itemsPerPage;
@property (nonatomic, assign) BOOL truncateFinalPage;
@property (nonatomic, strong, readonly) NSArray *indexesForVisibleItems;
@property (nonatomic, strong, readonly) NSArray *visibleItemViews;
@property (nonatomic, strong, readonly) UIView *currentItemView;
@property (nonatomic, assign) NSInteger currentItemIndex;
@property (nonatomic, assign) NSInteger currentPage;
@property (nonatomic, assign) SwipeViewAlignment alignment;
@property (nonatomic, assign) CGFloat scrollOffset;
@property (nonatomic, assign, getter = isPagingEnabled) BOOL pagingEnabled;
@property (nonatomic, assign, getter = isScrollEnabled) BOOL scrollEnabled;
@property (nonatomic, assign, getter = isWrapEnabled) BOOL wrapEnabled;
@property (nonatomic, assign) BOOL delaysContentTouches;
@property (nonatomic, assign) BOOL bounces;
@property (nonatomic, assign) float decelerationRate;
@property (nonatomic, assign) CGFloat autoscroll;
@property (nonatomic, readonly, getter = isDragging) BOOL dragging;
@property (nonatomic, readonly, getter = isDecelerating) BOOL decelerating;
@property (nonatomic, readonly, getter = isScrolling) BOOL scrolling;
@property (nonatomic, assign) BOOL defersItemViewLoading;
@property (nonatomic, assign, getter = isVertical) BOOL vertical;
@property (nonatomic, readonly) CGPoint contentOffset;

- (void)reloadData;
- (void)reloadItemAtIndex:(NSInteger)index;
- (void)scrollByOffset:(CGFloat)offset duration:(NSTimeInterval)duration;
- (void)scrollToOffset:(CGFloat)offset duration:(NSTimeInterval)duration;
- (void)scrollByNumberOfItems:(NSInteger)itemCount duration:(NSTimeInterval)duration;
- (void)scrollToItemAtIndex:(NSInteger)index duration:(NSTimeInterval)duration;
- (void)scrollToPage:(NSInteger)page duration:(NSTimeInterval)duration;
- (UIView *)itemViewAtIndex:(NSInteger)index;
- (NSInteger)indexOfItemView:(UIView *)view;
- (NSInteger)indexOfItemViewOrSubview:(UIView *)view;

- (UIView *)dequeueReusableViewWithIdentifier:(NSString *)identifier;

- (void)releaseResuableView;
@end


@protocol XDSwipeViewDataSource <NSObject>

@required
- (NSInteger)numberOfItemsInSwipeView:(XDSwipeView *)swipeView;
- (UIView *)swipeView:(XDSwipeView *)swipeView viewForItemAtIndex:(NSInteger)index;

@end

@protocol XDSwipeViewDelegate <NSObject>
@optional

- (CGSize)swipeViewItemSize:(XDSwipeView *)swipeView;
- (void)swipeViewDidScroll:(XDSwipeView *)swipeView;
- (void)swipeViewCurrentItemIndexDidChange:(XDSwipeView *)swipeView;
- (void)swipeViewWillBeginDragging:(XDSwipeView *)swipeView;
- (void)swipeViewDidEndDragging:(XDSwipeView *)swipeView willDecelerate:(BOOL)decelerate;
- (void)swipeViewWillBeginDecelerating:(XDSwipeView *)swipeView;
- (void)swipeViewDidEndDecelerating:(XDSwipeView *)swipeView;
- (void)swipeViewDidEndScrollingAnimation:(XDSwipeView *)swipeView;
- (BOOL)swipeView:(XDSwipeView *)swipeView shouldSelectItemAtIndex:(NSInteger)index;
- (void)swipeView:(XDSwipeView *)swipeView didSelectItemAtIndex:(NSInteger)index;

@end

@interface UIView (SwipeViewIdentifier)

- (void)setSwipeViewReseIdentifier:(NSString *)identifer;
- (NSString *)swipeViewReseIdentifier;
- (void)removeSwipeViewReseIdentifier;

@end
