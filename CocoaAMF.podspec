Pod::Spec.new do |s|
  s.name             = "CocoaAMF"
  s.version          = "1.2.0"
  s.license     	 = { :type => 'MIT', :file => 'LICENSE.txt' }
  
  s.summary          = "CocoaAMF - make communication with the server super fast, use AMF binary format"
  s.description      = <<-DESC
                       CocoaAMF is a set of classes which can make fast AMF0 and AMF3 remote-ing calls or act as a server to handle AMF requests. The communication in AMF format is almost 10x faster than same data structure in XML and JSON (http://census2.jamesward.com/). You can still use your existing web services by adding simple AMF bridge.
                       
                       Action Message Format (AMF) is a binary format used to serialize object graphs such as ActionScript objects and XML, or send messages between an Adobe Flash client and a remote service, usually a Flash Media Server or third party alternatives. This library provides classes for encoding and decoding from the AMF format.
                       DESC
  s.screenshots 	 = "https://github.com/jold/CocoaAMF/benchmark.png"
  s.homepage         = "https://github.com/jold/CocoaAMF"
  s.authors  		 = 'Daniel Jankovic', { 'Marc Bauer' => 'mb@nesium.com' }
  s.source           = { :git => "https://github.com/jold/CocoaAMF.git", :tag => s.version.to_s }

  s.source_files = 'CocoaAMF/*.{h,m}'
  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.7'
  s.requires_arc = false

  s.dependency 'CocoaAsyncSocket', '~> 7.3'
  s.dependency 'NSData+Base64', '~> 1.0'
end
