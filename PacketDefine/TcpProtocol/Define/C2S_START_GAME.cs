// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace TcpProtocol.Define
{

using global::System;
using global::System.Collections.Generic;
using global::FlatBuffers;

public struct C2S_START_GAME : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_2_0_0(); }
  public static C2S_START_GAME GetRootAsC2S_START_GAME(ByteBuffer _bb) { return GetRootAsC2S_START_GAME(_bb, new C2S_START_GAME()); }
  public static C2S_START_GAME GetRootAsC2S_START_GAME(ByteBuffer _bb, C2S_START_GAME obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public C2S_START_GAME __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public string Message { get { int o = __p.__offset(4); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetMessageBytes() { return __p.__vector_as_span<byte>(4, 1); }
#else
  public ArraySegment<byte>? GetMessageBytes() { return __p.__vector_as_arraysegment(4); }
#endif
  public byte[] GetMessageArray() { return __p.__vector_as_array<byte>(4); }

  public static Offset<TcpProtocol.Define.C2S_START_GAME> CreateC2S_START_GAME(FlatBufferBuilder builder,
      StringOffset messageOffset = default(StringOffset)) {
    builder.StartTable(1);
    C2S_START_GAME.AddMessage(builder, messageOffset);
    return C2S_START_GAME.EndC2S_START_GAME(builder);
  }

  public static void StartC2S_START_GAME(FlatBufferBuilder builder) { builder.StartTable(1); }
  public static void AddMessage(FlatBufferBuilder builder, StringOffset messageOffset) { builder.AddOffset(0, messageOffset.Value, 0); }
  public static Offset<TcpProtocol.Define.C2S_START_GAME> EndC2S_START_GAME(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<TcpProtocol.Define.C2S_START_GAME>(o);
  }
};


}
