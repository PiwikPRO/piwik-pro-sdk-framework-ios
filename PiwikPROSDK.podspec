Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.name         = "PiwikPROSDK"
  s.version      = "1.1.7"
  s.summary      = "Piwik PRO SDK for iOS"

  s.description  = "SDK for iOS to measure your apps with Piwik PRO"
  s.homepage     = "https://piwik.pro"


  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.license      = { :type => "MIT", :file => "LICENSE.md" }


  # ――― Author Metadata  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.author             = { "Piwik PRO" => "contact+cocoapods@piwik.pro" }
  s.social_media_url   = "http://twitter.com/piwikpro/"


  # ――― Platform Specifics ――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.platform     = :ios, "9.0"


  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.source       = { :git => "https://github.com/PiwikPRO/piwik-pro-sdk-framework-ios.git", :branch => "master", :tag => s.version.to_s}


  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.source_files = "PiwikPROSDK.xcframework/**/*.{h,m}"
  
  s.public_header_files = "PiwikPROSDK.xcframework/**/*.h"


  s.preserve_paths =  "PiwikPROSDK.xcframework/**/*"
 
  
  s.documentation_url 	= "http://developers.piwik.pro/en/latest/sdk/Piwik_PRO_SDK_for_iOS.html"
  
  s.frameworks   = "SystemConfiguration"

  s.ios.vendored_frameworks = "PiwikPROSDK.xcframework"

  s.requires_arc = false

  s.pod_target_xcconfig = { "HEADER_SEARCH_PATHS" => "$(PODS_ROOT)/**" }

  s.xcconfig     =  {
  "FRAMEWORK_SEARCH_PATHS" => "$(PODS_ROOT)/", 
  "USER_HEADER_SEARCH_PATHS" => "$(PODS_ROOT)/**", 
  "OTHER_LDFLAGS" => "$(inherited) -ObjC"
  }


  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #


  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #


  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #


end