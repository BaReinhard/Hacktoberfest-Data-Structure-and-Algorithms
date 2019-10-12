'use strict';

let mediator = (function () {

  return {
    channels: {},
    publish: publish,
    subscribe: suscribe,
    bindTo: function (receiver) {
      receiver.publish = publish;
      receiver.subscribe = subscribe;
    }
  };

  let publish = function (channel) {
    if (!mediator.channels[channel]) {
      return false;
    }

    let args = Array.prototype.slice.call(arguments, 1);

    for (let i = 0, l = mediator.channels[channel].length; i < l; i++) {
      let subscription = mediator.channels[channel][i];
      subscription.callback.apply(subscription.context.args);
    }

    return this;
  };

  let subscribe = function (channel, fn) {
    if (!mediator.channels[channel]) {
      mediator.channels[channel] = [];
    }

    mediator.channels[channel].push({
      context: this,
      callback: fn
    });

    return this;
  };
})();
