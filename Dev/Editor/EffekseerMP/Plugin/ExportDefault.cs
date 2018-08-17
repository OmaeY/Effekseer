﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Effekseer.Plugin
{
	class ExportDefault
	{
		public static string UniqueName
		{
			get
			{
				return "Default";
			}
		}

		public static string Author
		{
			get
			{
				return "Default";
			}
		}

		public static string Title
		{
			get
			{
				if (Effekseer.Core.Language == Effekseer.Language.Japanese) return "標準形式";
				return "Default format";
			}
		}

		public static string Description
		{
			get
			{
				if (Effekseer.Core.Language == Effekseer.Language.Japanese) return "標準形式で出力する。";
				return "Export as default format";
			}
		}

		public static string Filter
		{
			get
			{
				if (Effekseer.Core.Language == Effekseer.Language.Japanese) return "標準形式 (*.efk)|*.efk";
				return "Default format (*.efk)|*.efk";
			}
		}

		public static void Call(string path)
		{
			var window = new Magnification();
			window.Show(path);
		}

		class Magnification : Effekseer.GUI.IRemovableControl
		{
			string title = string.Empty;
			string message = string.Empty;
			string id = "###magnification";

			bool opened = true;

			bool isFirstUpdate = true;

			string path = string.Empty;
			float[] mag = new float[1];

			public bool ShouldBeRemoved { get; private set; }

			public Magnification()
			{
				ShouldBeRemoved = false;
			}

			public void Show(string path)
			{
				this.title = "Maginification";
				this.path = path;
				mag[0] = Effekseer.Core.Option.ExternalMagnification.GetValue();
				Effekseer.GUI.Manager.AddControl(this);
			}

			public void Update()
			{
				if (isFirstUpdate)
				{
					Effekseer.GUI.Manager.NativeManager.OpenPopup(id);
					isFirstUpdate = false;
				}

				if (Effekseer.GUI.Manager.NativeManager.BeginPopupModal(title + id, ref opened, Effekseer.swig.WindowFlags.AlwaysAutoResize))
				{
					if (Effekseer.GUI.Manager.NativeManager.DragFloat("Magnification", mag, 0.1f, 0, float.MaxValue))
					{

					}

					var save_text = "Save";
					if (Effekseer.Core.Language == Effekseer.Language.Japanese) save_text = "保存";

					if (Effekseer.GUI.Manager.NativeManager.Button(save_text))
					{
						var binary = Effekseer.Binary.Exporter.Export(mag[0]);
						System.IO.File.WriteAllBytes(path, binary);
						Effekseer.Core.Option.ExternalMagnification.SetValue(mag[0]);
						ShouldBeRemoved = true;
					}

					var cancel_text = "Cancel";
					if (Effekseer.Core.Language == Effekseer.Language.Japanese) cancel_text = "キャンセル";

					if (Effekseer.GUI.Manager.NativeManager.Button(cancel_text))
					{
						ShouldBeRemoved = true;
					}

					Effekseer.GUI.Manager.NativeManager.EndPopup();
				}
				else
				{
					ShouldBeRemoved = true;
				}
			}
		}
	}
}