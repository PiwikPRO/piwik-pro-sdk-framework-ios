// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "PiwikPROSDK",
    products: [
        .library(
            name: "PiwikPROSDK",
            targets: ["PiwikPROSDKWrapper"]),
    ],
    targets: [
        .target(
          name: "PiwikPROSDKWrapper",
          dependencies: ["PiwikPROSDK"],
          path: "PiwikPROSDK-Wrapper",
          resources: [.process("Resources/PrivacyInfo.xcprivacy")]
        ),
        .binaryTarget(name: "PiwikPROSDK", path: "./PiwikPROSDK.xcframework"),
    ]
)
