open Task;

module Make = (Messages: Messages.S) => {
  type exchangeT;
  //  name: name,
  //     type: type,
  //     options: options,
  //     queue: createQueue,
  //     connect: connect,
  //     publish: publish
  type queueT;
  // name: options.name,
  //     options: _.extend({}, DEFAULT_QUEUE_OPTIONS, options),
  //     connect: connect,
  //     consume: consume,
  //     cancel: cancel,
  //     purge: purge

  [@bs.send] external topic : (Connection.rabbitT, string) => exchangeT = "topic";

  type publishOptions;

  external makePublishOptions :
  (
    ~key: string=?,
    unit
  ) =>
  publishOptions =
  "";

  [@bs.send] external _publish : (exchangeT, 'a, publishOptions) => exchangeT = "publish";

  let publish = (exchange: exchangeT, obj: Messages.publisherMsg, options: publishOptions) => _publish(exchange, Messages.publisherMsgToValidJson(obj), options);

  type queueOptions;
  [@bs.obj]
  external makeQueueOptions :
  (
    ~name: string=?,
    ~exclusive: bool=?,
    ~keys: array(string)=?,
    ~durable: string=?,
    unit
  ) =>
  queueOptions =
  "";
  [@bs.send] external createQueue : (exchangeT, queueOptions) => queueT = "queue";

  module Queue = {
    [@bs.send] external _consume : (queueT, ('a, option(string) => unit) => unit) => unit = "consume";
    // Todo make this cancelable
    let consumer = queue => Task((_, res) => {
      let tomsg: 'a => Messages.publisherMsg = (obj) => Messages.publisherMsgFromValidJson(obj);
      _consume(queue, (obj, acc) => res((tomsg(obj), acc)))
      NoCancel;
    })
  }
}