// swift-tools-version:5.1
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription
import Foundation

let package = Package(
    name: "testProfitBot",
    products: [
        // Products define the executables and libraries produced by a package, and make them visible to other packages.
        .executable(
            name: "testProfitBot",
            targets: ["testProfitBot"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/zmeyc/telegram-bot-swift.git", from: "1.1.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages which this package depends on.
        .target(
            name: "testProfitBot",
            dependencies: ["TelegramBotSDK"]),
        .testTarget(
            name: "testProfitBotTests",
            dependencies: ["TelegramBotSDK"]),
    ]
)

func resolvePort() -> Int {
    let defaulPort = 8080
    if let requestedPort = ProcessInfo.processInfo.environment["PORT"]{
        return Int(requestedPort) ?? defaulPort
    }
    return defaulPort
}
