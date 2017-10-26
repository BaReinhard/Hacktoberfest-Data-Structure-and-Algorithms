const LEGAL_VALUES = 'abcdefghijklmnopqrstuvwxyz';
const START_CODE = 'a'.charCodeAt(0);
const END_CODE = 'z'.charCodeAt(0);

class CaesarCipher {
  constructor(key) {
    if (key === undefined) {
      this.generateKey();

    } else {
      this.key = key;
      this.validateKey();
    }
  }

  generateKey() {
    this.key = '';

    for (let i = 0; i < 100; i++) {
      let randomIdx = Math.floor(Math.random() * 26);
      this.key += LEGAL_VALUES.charAt(randomIdx);
    }
  }

  validateKey() {
    const emptyKey = this.key.length < 1;
    const hasInvalidChars = this.key.split('').some(letter => {
      return LEGAL_VALUES.indexOf(letter) === -1;
    });

    if (emptyKey || hasInvalidChars) {
      throw new Error('Bad key');
    }
  }

  encode(decodedMessage) {
    let longKey = this.key;
    let encodedMessage = "";

    while (longKey.length < decodedMessage.length) {
      longKey += longKey;
    }

    decodedMessage.split('').forEach((letter, idx) => {
      const currentKeyCode = longKey.charCodeAt(idx);
      const offset = (currentKeyCode - START_CODE);
      let newCharCode = letter.charCodeAt(0) + offset;

      if (newCharCode > END_CODE) {
        newCharCode -= LEGAL_VALUES.length;
      }

      encodedMessage += String.fromCharCode(newCharCode);
    });

    return encodedMessage;
  }

  decode(encodedMessage) {
    let longKey = this.key;
    let decodedMessage = "";

    while (longKey.length < encodedMessage.length) {
      longKey += longKey;
    }

    encodedMessage.split('').forEach((letter, idx) => {
      const currentKeyCode = longKey.charCodeAt(idx);
      const offset = (currentKeyCode - START_CODE);
      let newCharCode = letter.charCodeAt(0) - offset;

      if (newCharCode < START_CODE) {
        newCharCode += LEGAL_VALUES.length;
      }

      decodedMessage += String.fromCharCode(newCharCode);
    });

    return decodedMessage;
  }
}

module.exports = CaesarCipher;
