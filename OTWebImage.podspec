Pod::Spec.new do |s|
  s.name        = "OTWebImage"
  s.version     = "1.0.0"
  s.summary     = "Asynchronous image downloader with cache support with an NSImageView category"
  s.homepage    = "https://github.com/OpenFibers/OTWebImage"
  s.license     = { :type => "MIT" }
  s.authors     = { "Open Thread" => "openfibers@gmail.com" }

  s.platform = :osx, "10.9"
  s.source   = { :git => "https://github.com/mblsha/OTWebImage" }

  s.source_files = "OTWebImage/*", "OTWebImage/OTFileCacheManager/*", "OTWebImage/OTHTTPRequest/*"
  s.public_header_files = "OTWebImage/NSImageView+WebCache.h"

  s.requires_arc = true
end
