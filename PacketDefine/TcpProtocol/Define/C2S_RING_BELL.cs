// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace TcpProtocol.Define
{

using global::System;
using global::System.Collections.Generic;
using global::FlatBuffers;

public struct C2S_RING_BELL : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_2_0_0(); }
  public static C2S_RING_BELL GetRootAsC2S_RING_BELL(ByteBuffer _bb) { return GetRootAsC2S_RING_BELL(_bb, new C2S_RING_BELL()); }
  public static C2S_RING_BELL GetRootAsC2S_RING_BELL(ByteBuffer _bb, C2S_RING_BELL obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public C2S_RING_BELL __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public int Playernum { get { int o = __p.__offset(4); return o != 0 ? __p.bb.GetInt(o + __p.bb_pos) : (int)0; } }

  public static Offset<TcpProtocol.Define.C2S_RING_BELL> CreateC2S_RING_BELL(FlatBufferBuilder builder,
      int playernum = 0) {
    builder.StartTable(1);
    C2S_RING_BELL.AddPlayernum(builder, playernum);
    return C2S_RING_BELL.EndC2S_RING_BELL(builder);
  }

  public static void StartC2S_RING_BELL(FlatBufferBuilder builder) { builder.StartTable(1); }
  public static void AddPlayernum(FlatBufferBuilder builder, int playernum) { builder.AddInt(0, playernum, 0); }
  public static Offset<TcpProtocol.Define.C2S_RING_BELL> EndC2S_RING_BELL(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<TcpProtocol.Define.C2S_RING_BELL>(o);
  }
};


}
