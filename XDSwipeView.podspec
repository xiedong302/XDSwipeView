Pod::Spec.new do |s|
  s.name         = "XDSwipeView"
  s.version      = "1.0.0"
  s.summary      = "An easy way to use view"
  s.description  = <<-DESC
		   It is marquee view used on IOS,which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/xiedong302/XDSwipeView"
  s.license          = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "xiedong302" => "13545861221@163.com" }
  s.platform = :ios, '7.0'
  s.source       = { :git => "https://github.com/xiedong302/XDSwipeView.git", :tag => s.version.to_s }
  s.source_files  = 'XDSwipeView/*'
  s.requires_arc = true
end
