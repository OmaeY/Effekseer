﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Effekseer.Data
{
	public class LocationValues
	{
		[Selector(ID = 0)]
		public Value.Enum<ParamaterType> Type
		{
			get;
			private set;
		}

		[Selected(ID = 0, Value = 0)]
		[IO(Export = true)]
		public FixedParamater Fixed
		{
			get;
			private set;
		}

		[Selected(ID = 0, Value = 1)]
		[IO(Export = true)]
		public PVAParamater PVA
		{
			get;
			private set;
		}

		[Selected(ID = 0, Value = 2)]
		[IO(Export = true)]
		public Vector3DEasingParamater Easing
		{
			get;
			private set;
		}

		[Selected(ID = 0, Value = 3)]
		[IO(Export = true)]
		public Vector3DFCurveParameter LocationFCurve
		{
			get;
			private set;
		}

#if __EFFEKSEER_BUILD_VERSION16__
		[Selected(ID = 0, Value = 4)]
		[IO(Export = true)]
		public NurbsCurveParameter NurbsCurve
		{
			get;
			private set;
		}

		[Selected(ID = 0, Value = 5)]
		[IO(Export = true)]
		public ViewOffsetParameter ViewOffset
		{
			get;
			private set;
		}
#endif

		internal LocationValues()
		{
			Type = new Value.Enum<ParamaterType>(ParamaterType.Fixed);
			Fixed = new FixedParamater();
			PVA = new PVAParamater();
			Easing = new Vector3DEasingParamater();
			LocationFCurve = new Vector3DFCurveParameter();
#if __EFFEKSEER_BUILD_VERSION16__
			NurbsCurve = new NurbsCurveParameter();
			ViewOffset = new ViewOffsetParameter();
#endif

			// dynamic parameter
			Fixed.Location.CanSelectDynamicEquation = true;
			PVA.Location.CanSelectDynamicEquation = true;
			PVA.Velocity.CanSelectDynamicEquation = true;
			PVA.Acceleration.CanSelectDynamicEquation = true;
			Easing.Start.CanSelectDynamicEquation = true;
			Easing.End.CanSelectDynamicEquation = true;
		}

		public class FixedParamater
		{
			[Key(key = "Position_FixedParamater_Location")]
			public Value.Vector3D Location
			{
				get;
				private set;
			}

			internal FixedParamater()
			{
				Location = new Value.Vector3D(0, 0, 0);
			}
		}

		public class PVAParamater
		{
			[Key(key = "Position_PVAParamater_Location")]
			public Value.Vector3DWithRandom Location
			{
				get;
				private set;
			}

			[Key(key = "Position_PVAParamater_Velocity")]
			public Value.Vector3DWithRandom Velocity
			{
				get;
				private set;
			}

			[Key(key = "Position_PVAParamater_Acceleration")]
			public Value.Vector3DWithRandom Acceleration
			{
				get;
				private set;
			}

#if __EFFEKSEER_BUILD_VERSION16__
			[Name(language = Language.Japanese, value = "力場[抵抗]による影響を受ける")]
			[Name(language = Language.English, value = "Affected by the force field [Drag]")]
			[IO(Export = true)]
			public Value.Boolean EnableAffectedDrag
			{
				get;
				private set;
			}
#endif

			internal PVAParamater()
			{
				Location = new Value.Vector3DWithRandom(0, 0, 0);
				Velocity = new Value.Vector3DWithRandom(0, 0, 0);
				Acceleration = new Value.Vector3DWithRandom(0, 0, 0);
#if __EFFEKSEER_BUILD_VERSION16__
				EnableAffectedDrag = new Value.Boolean(false);
#endif
			}
		}

#if __EFFEKSEER_BUILD_VERSION16__
		public class NurbsCurveParameter
		{
			public enum NurbsLoopType : int
			{
				[Name(language = Language.Japanese, value = "繰り返す")]
				[Name(language = Language.English, value = "Repeat")]
				Repeat = 0,

				[Name(language = Language.Japanese, value = "停止")]
				[Name(language = Language.English, value = "Stop")]
				Stop = 1,
			}

			[Name(language = Language.Japanese, value = "NURBSカーブ")]
			[Name(language = Language.English, value = "NURBS-Curve")]
			[IO(Export = true)]
			public Value.PathForCurve FilePath
			{
				get;
				private set;
			}

			[Name(language = Language.Japanese, value = "カーブ拡大率")]
			[Name(language = Language.English, value = "Curve Scale")]
			[IO(Export = true)]
			public Value.Float Scale
			{
				get;
				private set;
			}

			[Name(language = Language.Japanese, value = "移動速度")]
			[Name(language = Language.English, value = "Move Speed")]
			[IO(Export = true)]
			public Value.Float MoveSpeed
			{
				get;
				private set;
			}

			[Name(language = Language.Japanese, value = "ループタイプ")]
			[Name(language = Language.English, value = "LoopType")]
			[IO(Export = true)]
			public Value.Enum<NurbsLoopType> LoopType
			{
				get;
				private set;
			}

			public NurbsCurveParameter()
			{
				FilePath = new Value.PathForCurve(Resources.GetString("CurveFilter"), true, "");
				Scale = new Value.Float(1.0f);
				MoveSpeed = new Value.Float(1.0f, float.MaxValue, 0.0f);
				LoopType = new Value.Enum<NurbsLoopType>(NurbsLoopType.Repeat);
			}
		}

		public class ViewOffsetParameter
		{
			[Name(language = Language.Japanese, value = "距離")]
			[Name(language = Language.English, value = "Distance")]
			[IO(Export = true)]
			public Value.FloatWithRandom Distance
			{
				get;
				private set;
			}

			public ViewOffsetParameter()
			{
				Distance = new Value.FloatWithRandom(3.0f, float.MaxValue, 0.0f, DrawnAs.CenterAndAmplitude, 0.5f);
			}
		}
#endif

		public enum ParamaterType : int
		{
			[Key(key = "Position_ParamaterType_Fixed")]
			Fixed = 0,
			[Key(key = "Position_ParamaterType_PVA")]
			PVA = 1,
			[Key(key = "Position_ParamaterType_Easing")]
			Easing = 2,
			[Key(key = "Position_ParamaterType_LocationFCurve")]
			LocationFCurve = 3,
#if __EFFEKSEER_BUILD_VERSION16__
			[Name(language = Language.Japanese, value = "位置(NURBSカーブ)")]
			[Name(language = Language.English, value = "NURBS-Curve")]
			NurbsCurve = 4,

			[Name(language = Language.Japanese, value = "カメラオフセット")]
			[Name(language = Language.English, value = "View Offset")]
			ViewOffset = 5,
#endif
		}
	}
}
