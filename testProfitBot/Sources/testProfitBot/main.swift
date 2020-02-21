print("Hello, world!")

import Foundation
import TelegramBotSDK

let token = "847811913:AAFZ-yvbDN7OvbVAqTgcqt7YKF_Eq_gVuBM"
let bot = TelegramBot(token: token)

while let update = bot.nextUpdateSync() {
    if let message = update.message, let from = message.from, let text = message.text {
        bot.sendMessageAsync(chatId: from.id,
                             text: "Hi \(from.firstName)! You said: \(text).\n")
    }
}

fatalError("Server stopped due to error: \(bot.lastError)")