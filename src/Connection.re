type rabbitT;
// default: createDefaultExchange,
// direct: createExchange("direct"),
// fanout: createExchange("fanout"),
// topic: createExchange("topic"),
// close: close,
// getInternals: getInternals

type urlObjT;

[@bs.obj]
external makeUrlObj :
(
  ~protocol: string=?,
  ~hostname: string=?,
  ~port: int=?,
  ~username: string=?,
  ~password: string=?,
  ~local: string=?,
  ~frameMax: int=?,
  ~heartbeat: int=?,
  ~vhost: string=?,
  unit
) =>
urlObjT =
"";
[@bs.module] external create : string => rabbitT = "jackrabbit";
[@bs.module] external createWithUrlObj : urlObjT => rabbitT = "jackrabbit";

type socketOptionsT;

[@bs.obj]
external makeSocketOptions :
  (
    ~cert: string=?,
    ~key: string=?,
    ~passphrase: string=?,
    ~ca: array(string)=?,
    unit
  ) =>
  socketOptionsT =
  "";

[@bs.module] external createWithSocketOptions : (string, socketOptionsT) => rabbitT = "jackrabbit";
[@bs.module] external createWithUrlObjAndSocketOption : (urlObjT, socketOptionsT) => rabbitT = "jackrabbit";

[@bs.send] external on: (rabbitT, string, unit => unit) => unit = "on";

