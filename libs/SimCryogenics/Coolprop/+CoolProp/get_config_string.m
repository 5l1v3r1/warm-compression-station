function varargout = get_config_string(varargin)
  [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(337,varargin{:});
end
